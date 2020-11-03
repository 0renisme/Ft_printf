/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:49:46 by oren              #+#    #+#             */
/*   Updated: 2020/10/30 19:00:05 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_len_dest(unsigned int n, int base)
{
	int len_dest;

	len_dest = 1;
	if (n < 0)
	{
		len_dest++;
		n = -n;
	}
	while (n > 0)
	{
		n /= base;
		len_dest++;
	}
	return (len_dest);
}

char	*ft_itoa_base(unsigned int n, char *base)
{
	char			*dest;
	int				len_dest;
	int				base_integer;
	unsigned int	n_cpy;

	base_integer = ft_strlen(base);
	len_dest = find_len_dest(n, base_integer);
	if (!(dest = malloc(sizeof(char) * len_dest + 1)))
		return (0);
	len_dest = 0;
	n_cpy = n;
	while (n_cpy > 0)
	{
		dest[len_dest] = base[n_cpy % base_integer];
		n_cpy /= base_integer;
		len_dest++;
	}
	dest[len_dest] = 0;
	dest = ft_strrev(dest);
	return (dest);
}

int		find_len_dest_long(unsigned int n, int base)
{
	int len_dest;

	len_dest = 1;
	if (n < 0)
	{
		len_dest++;
		n = -n;
	}
	while (n > 0)
	{
		n /= base;
		len_dest++;
	}
	return (len_dest);
}

char	*ft_itoa_long_base(unsigned long int n, char *base)
{
	char				*dest;
	int					len_dest;
	int					base_integer;
	unsigned long int	n_cpy;

	base_integer = ft_strlen(base);
	len_dest = find_len_dest_long(n, base_integer);
	if (!(dest = malloc(sizeof(char) * len_dest + 1)))
		return (0);
	len_dest = 0;
	n_cpy = n;
	while (n_cpy > 0)
	{
		dest[len_dest] = base[n_cpy % base_integer];
		n_cpy /= base_integer;
		len_dest++;
	}
	dest[len_dest] = 0;
	dest = ft_strrev(dest);
	return (dest);
}
