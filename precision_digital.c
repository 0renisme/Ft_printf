/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_digital.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:56:24 by oren              #+#    #+#             */
/*   Updated: 2020/11/03 02:35:29 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_with_digital(char *str, int i)
{
	int j;

	j = i;
	if (str[i] == '0')
		return (0);
	while (ft_isdigit(str[j]))
		j++;
	if ((find_index(str[j], "csdiuxXp%")) != -1)
		return (i);
	if (str[j] == '.')
	{
		if (str[j + 1] == '*' && (find_index(str[j], "csdiuxXp%")) != -1)
			return (i);
		if (ft_isdigit(str[j + 1]))
		{
			while (ft_isdigit(str[j + 1]))
				j++;
			if ((find_index(str[j + 1], "csdiuxXp%")) != -1)
				return (i);
		}
	}
	return (-1);
}

char	*digital(va_list *my_list, char *str, int i)
{
	char		*arg;
	char		*dest;
	int			number;

	number = my_atoi_substr(str, i);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		if (!(dest = point(my_list, str, i)))
			return (0);
		return (dest);
	}
	if ((find_index(str[i], "csdiuxXp%")) == -1)
		return (0);
	if (!(arg = tab_fonction(my_list, str, i - 1)))
		return (0);
	if (!(dest = with_charc_before(arg, number, ' ')))
		return (0);
	free(arg);
	return (dest);
}
