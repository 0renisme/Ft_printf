/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_ascii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 23:30:08 by oren              #+#    #+#             */
/*   Updated: 2020/11/02 11:03:08 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*character(va_list *my_list, char *str, int i)
{
	char c;
	char *dest;

	(void)i;
	(void)str;
	c = va_arg(*my_list, int);
	if (!(dest = malloc(sizeof(char) * 2)))
		return (0);
	if (c != 0 && c != -2)
	{
		dest[0] = c;
		dest[1] = 0;
	}
	else if (c == -2)
	{
		dest[0] = -3;
		dest[1] = 0;
	}
	else
	{
		dest[0] = -2;
		dest[1] = 0;
	}
	return (dest);
}

char	*string(va_list *my_list, char *str, int i)
{
	char *temp;
	char *dest;

	(void)i;
	(void)str;
	temp = va_arg(*my_list, char *);
	if (temp == NULL)
		dest = ft_strdup("(null)");
	else
		dest = ft_strdup(temp);
	return (dest);
}

char	*pointer(va_list *my_list, char *str, int i)
{
	unsigned long int	num;
	char				*dest;

	(void)i;
	(void)str;
	num = (unsigned long)va_arg(*my_list, void *);
	if (num == 0)
	{
		if (!(dest = ft_strdup("0x0")))
			return (0);
		return (dest);
	}
	if (!(dest = ft_itoa_long_base(num, "0123456789abcdef")))
		return (0);
	if (!(dest = ft_strjoin("0x", dest)))
		return (0);
	return (dest);
}

char	*percent(va_list *my_list, char *str, int i)
{
	char *dest;

	(void)i;
	(void)str;
	(void)my_list;
	if (!(dest = malloc(sizeof(char) * 2)))
		return (0);
	dest[0] = '%';
	dest[1] = 0;
	return (dest);
}
