/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 23:12:29 by oren              #+#    #+#             */
/*   Updated: 2020/11/03 01:58:58 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Returns the contents of the string, up to the next percent.
*/

int		up_to_the_percent_sign(char *str, int i)
{
	while (str[i] && str[i] != '%')
		i++;
	return (i);
}

/*
**	Advence after the last char of the arguments after the temporary assignment.
*/

int		good_position(char *str, int i)
{
	if (str[i] == '%')
	{
		if (ft_isdigit(str[i + 1]) || str[i + 1] == '-' || str[i + 1] == '.' ||
		str[i + 1] == '*')
		{
			while (ft_isdigit(str[i + 2]) || str[i + 2] == '*' ||
			str[i + 2] == '.' || str[i + 2] == '-')
				i++;
			i++;
		}
		return (i + 2);
	}
	i = up_to_the_percent_sign(str, i);
	return (i);
}

/*
**	Find it	|
**	here	\/
*/

int		find_index(char c, char *index_tab)
{
	int			index;

	index = 0;
	while (index_tab[index])
	{
		if (index_tab[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

/*
**	Contains my functions accebible with an index.
*/

char	*tab_fonction(va_list *my_list, char *str, int i)
{
	static char	*(*precision[14]) (va_list *, char *, int) = {character, string,
	integer, integerr, pointer, unsigned_integer, hexa_min, hexa_maj, percent,
	minus, zero, star, point, digital};
	char		*dest;
	int			index;

	if (str[i + 1] > '0' && str[i + 1] <= '9')
		index = 13;
	else if ((index = find_index(str[i + 1], "csdipuxX%-0*.")) == -1)
		return (0);
	if ((index > 8 && index < 12) && (str[i + 1] == '.'))
	{
		index = 12;
		i++;
	}
	if (!(dest = precision[index](my_list, str, i + 1)))
		return (0);
	return (dest);
}

/*
**	Fill the string to return with the arg if str[i] is percent.
**	Else, fill the string to return until the next percent.
*/

char	*fill_temp(va_list *my_list, char *str, int i)
{
	char	*temp;
	int		j;

	temp = 0;
	if (str[i] == '%')
	{
		if (!(temp = tab_fonction(my_list, str, i)))
			return (0);
	}
	else
	{
		j = up_to_the_percent_sign(str, i);
		if (!(temp = ft_substr(str, i, j)))
			return (0);
	}
	return (temp);
}
