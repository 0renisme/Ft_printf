/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:21:17 by oren              #+#    #+#             */
/*   Updated: 2020/11/03 02:04:10 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

short	check_error_zero(char *str, int i)
{
	while (str[i] == '0')
		i++;
	if (str[i] == '*')
		i++;
	else if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			i++;
	}
	if (str[i] == '.')
		return (1);
	if (find_index(str[i], "sdiuxX%") > -1)
		return (1);
	return (0);
}

char	*fill_dest_zero_if_minus_or_not(char pos, char *arg, int number)
{
	char	*dest;
	char	*temp;
	char	*temp2;

	if (!(number < 0))
	{
		if ((pos == 'i' || pos == 'd') && arg[0] == '-')
		{
			if (!(temp = ft_substr(arg, 1, ft_strlen(arg))))
				return (0);
			temp2 = with_charc_before(temp, number - 1, '0');
			dest = ft_strjoin("-", temp2);
			free(temp);
		}
		else
			dest = with_charc_before(arg, number, '0');
	}
	else
	{
		number = -number;
		dest = with_charc_after(arg, number, ' ');
	}
	free(arg);
	return (dest);
}

char	*fill_dest_zero(va_list *my_list, char *str, int i)
{
	char	*arg;
	int		number;

	if (str[i] == '*')
		number = va_arg(*my_list, int);
	else
		number = my_atoi_substr(str, i);
	while (str[i] == '*' || ft_isdigit(str[i]))
		i++;
	if (!(arg = tab_fonction(my_list, str, i - 1)))
		return (0);
	return (fill_dest_zero_if_minus_or_not(str[i], arg, number));
}

char	*zero(va_list *my_list, char *str, int i)
{
	int			number;
	char		*dest;

	if (is_string_b(str, i, '0', '-'))
		return (minus(my_list, str, i));
	if ((check_error_zero(str, i)) == 0)
		return (0);
	i = pass_zero_and_minus(str, i);
	if ((number = have_point_in_str(str, i)) > 0)
	{
		dest = point(my_list, str, number);
		return (dest);
	}
	dest = fill_dest_zero(my_list, str, i);
	return (dest);
}
