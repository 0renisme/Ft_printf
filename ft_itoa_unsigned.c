/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oren <orfreoua@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:50:31 by oren              #+#    #+#             */
/*   Updated: 2020/09/29 15:50:33 by oren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_unsigned(size_t n)
{
	size_t	i;
	size_t	nb;
	char	*str;

	if (n == 0)
		return (exception());
	i = compt_for_malloc(n);
	if (n < 0)
		nb = (unsigned int)(n * -1) + (0 * i++);
	else
		nb = (unsigned int)n;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str = fill_the_string(nb, n, str, 0);
	str = ft_strrev(str);
	return (str);
}
