/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:57:30 by oren              #+#    #+#             */
/*   Updated: 2020/11/02 11:03:29 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		end(char *dest)
{
	int i;

	i = 0;
	while (dest[i])
	{
		if (dest[i] == -2)
			write(1, "\0", 1);
		else
			write(1, &dest[i], 1);
		i++;
	}
	free(dest);
	return (i);
}

int		free_error(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (-1);
}

int		ft_printf(const char *str, ...)
{
	char	*dest;
	char	*temp;
	va_list	my_list;
	int		i;
	char	*swp;

	if (!(dest = malloc(1)))
		return (-1);
	dest[0] = 0;
	va_start(my_list, str);
	i = 0;
	while (str[i])
	{
		if (!(temp = fill_temp(&my_list, (char *)str, i)))
			return (free_error(temp, dest));
		i = good_position((char *)str, i);
		swp = dest;
		if (!(dest = ft_strjoin(dest, temp)))
			return (free_error(temp, dest));
		free(swp);
	}
	va_end(my_list);
	return (end(dest));
}
