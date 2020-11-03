/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:49:19 by oren              #+#    #+#             */
/*   Updated: 2020/10/09 15:59:36 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cpt_after_whitespace(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	int sign;
	int result;
	int i;

	sign = 1;
	result = 0;
	i = cpt_after_whitespace(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int		my_atoi_substr(char *str, int i)
{
	int		num;
	int		j;
	char	*num_ascii;

	j = i + 1;
	num = 0;
	while (ft_isdigit(str[j]))
		j++;
	if (!(num_ascii = (ft_substr(str, i, j))))
	{
		num_ascii = 0;
		free(num_ascii);
	}
	else
	{
		num = ft_atoi(num_ascii);
		free(num_ascii);
	}
	return (num);
}
