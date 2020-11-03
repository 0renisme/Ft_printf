/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_stars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:18:44 by oren              #+#    #+#             */
/*   Updated: 2020/10/09 14:04:22 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_error_star(int number, char *str, int i)
{
	int index;

	if (!(number < 2147483647 && number > -2147483647))
		return (-1);
	if ((index = find_index(str[i + 1], "csdiuxXp%")) == -1)
		return (-1);
	return (index);
}

char	*point_after_star(va_list *my_list, char *str, int i)
{
	char *dest;

	if (!(dest = point(my_list, str, i)))
		return (0);
	return (dest);
}

int		check_with_star(char *str, int i)
{
	int j;

	if ((find_index(str[i + 1], "csdiuxX%")) != -1)
		return (i);
	if (str[i + 1] == '.')
	{
		if ((find_index(str[i + 2], "csdiuxX%")) != -1)
			return (i);
		if (str[i + 2] == '*' && ((find_index(str[i + 3], "csdiuxX%")) != -1))
			return (i);
		if (ft_isdigit(str[i + 2]))
		{
			j = i;
			while (ft_isdigit(str[j + 2]))
				j++;
			if ((find_index(str[j + 2], "csdiuxX%")) != -1)
				return (i);
		}
	}
	return (-1);
}

char	*star(va_list *my_list, char *str, int i)
{
	int			number;
	char		*arg;
	char		*dest;

	if (str[i + 1] == '.')
	{
		dest = point_after_star(my_list, str, i + 1);
		return (dest);
	}
	number = va_arg(*my_list, int);
	if (!(arg = tab_fonction(my_list, str, i)))
		return (0);
	if (number < 0)
	{
		number = -number;
		if (!(dest = with_charc_after(arg, number, ' ')))
			return (0);
	}
	else
	{
		if (!(dest = with_charc_before(arg, number, ' ')))
			return (0);
	}
	free(arg);
	return (dest);
}
