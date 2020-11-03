/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:27:32 by orfreoua          #+#    #+#             */
/*   Updated: 2020/11/02 23:58:35 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		value_before_point(va_list *my_list, char *str, int i)
{
	int num_before;
	int xten;

	num_before = 0;
	xten = 1;
	if (str[i] == '*')
		num_before = va_arg(*my_list, int);
	else if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
		{
			num_before += ((str[i] - 48) * xten);
			xten *= 10;
			i--;
		}
		i++;
	}
	if (str[i - 1] == '-' && num_before > 0)
		num_before = -num_before;
	return (num_before);
}

int		value_after_point(va_list *my_list, char *str, int i)
{
	int num_after;
	int xten;

	num_after = 0;
	xten = 1;
	if (str[i] == '*')
		num_after = va_arg(*my_list, int);
	else if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			i++;
		i--;
		while (ft_isdigit(str[i]))
		{
			num_after += ((str[i] - 48) * xten);
			xten *= 10;
			i--;
		}
	}
	return (num_after);
}

int		repetition_of_char_c(char *str, int i, char c, short index)
{
	if (index == 1)
	{
		while (str[i] == c)
			i--;
		if (str[i] == '%')
			return (1);
	}
	else
	{
		while (ft_isdigit(str[i]))
			i++;
		if ((find_index(str[i], "sdiuxX%")) != -1)
			return (1);
	}
	return (0);
}

int		check_before_point(char *str, int i)
{
	if (str[i] == '-' && str[i - 1] == '%')
		return (1);
	if (str[i] == '%')
		return (1);
	else if (str[i] == '*')
	{
		if (str[i - 1] == '-')
			return (repetition_of_char_c(str, i - 1, '-', 1));
		else if (str[i - 1] == '0')
			return (repetition_of_char_c(str, i - 1, '0', 1));
		if (str[i - 1] == '%')
			return (1);
	}
	else if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i - 1]))
			i--;
		if (str[i - 1] == '%')
			return (1);
		if ((str[i - 1] == '-' && str[i] != '0') || str[i - 1] == '0')
			return (repetition_of_char_c(str, i - 2, str[i - 1], 1));
	}
	else if (str[i - 1] == '-')
		return (repetition_of_char_c(str, i - 1, '-', 1));
	return (0);
}

int		check_after_point(char *str, int i)
{
	if (find_index(str[i], "cspdiuxX%") != -1)
		return (1);
	else if (str[i] == '*')
	{
		if (find_index(str[i + 1], "sdiuxX%") != -1)
			return (1);
	}
	else if (ft_isdigit(str[i]))
		return (repetition_of_char_c(str, i, '0', 2));
	else if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			i++;
		if (find_index(str[i], "cspdiuxX%") != -1)
			return (1);
	}
	return (0);
}
