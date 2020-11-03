/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 04:10:38 by oren              #+#    #+#             */
/*   Updated: 2020/11/03 04:21:05 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

short	check_error_minus(char *str, int i)
{
	while (str[i] == '-' || str[i] == '0')
		i++;
	if (str[i] == '*')
		i++;
	else if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			i++;
	}
	if (str[i] == '.')
	{
		i++;
		if (str[i] == '*')
			i++;
		else
		{
			while (ft_isdigit(str[i]))
				i++;
		}
	}
	if (find_index(str[i], "cspdiuxX%") > -1)
		return (1);
	return (0);
}

short	is_string_b(char *str, int i, char a, char b)
{
	while (str[i] == a)
		i++;
	if (str[i] == b)
		return (1);
	return (0);
}

int		pass_zero_and_minus(char *str, int i)
{
	while (str[i] == '-' || str[i] == '0')
		i++;
	return (i);
}

char	*redirect(char *arg, int *value, char sign, char pos)
{
	if (find_index(pos, "diuxX") > -1)
		return (fill_dest_minus(arg, value, sign));
	if (pos == 'p')
		return (fill_pointer(arg, value, sign));
	else
		return (fill_char_and_string(arg, value, sign, pos));
}
