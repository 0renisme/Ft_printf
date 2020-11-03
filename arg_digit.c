/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 23:30:26 by oren              #+#    #+#             */
/*   Updated: 2020/11/02 10:38:17 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*integer(va_list *my_list, char *str, int i)
{
	int		num;
	char	*dest;

	(void)i;
	(void)str;
	num = va_arg(*my_list, int);
	if (!(dest = ft_itoa(num)))
		return (0);
	return (dest);
}

char	*integerr(va_list *my_list, char *str, int i)
{
	int		num;
	char	*dest;

	(void)i;
	(void)str;
	num = va_arg(*my_list, int);
	if (!(dest = ft_itoa(num)))
		return (0);
	return (dest);
}

char	*unsigned_integer(va_list *my_list, char *str, int i)
{
	int				num;
	unsigned int	conversion;
	char			*dest;

	(void)i;
	(void)str;
	num = va_arg(*my_list, int);
	conversion = num;
	if (!(dest = ft_itoa_unsigned(conversion)))
		return (0);
	return (dest);
}

char	*hexa_min(va_list *my_list, char *str, int i)
{
	unsigned int	conversion;
	int				num;
	char			*dest;

	(void)i;
	(void)str;
	num = va_arg(*my_list, int);
	if (num == 0)
	{
		if (!(dest = ft_strdup("0")))
			return (0);
		return (dest);
	}
	conversion = num;
	if (!(dest = ft_itoa_base(conversion, "0123456789abcdef")))
		return (0);
	return (dest);
}

char	*hexa_maj(va_list *my_list, char *str, int i)
{
	unsigned int	conversion;
	int				num;
	char			*dest;

	(void)i;
	(void)str;
	num = va_arg(*my_list, int);
	if (num == 0)
	{
		if (!(dest = ft_strdup("0")))
			return (0);
		return (dest);
	}
	conversion = num;
	if (!(dest = ft_itoa_base(conversion, "0123456789ABCDEF")))
		return (0);
	return (dest);
}
