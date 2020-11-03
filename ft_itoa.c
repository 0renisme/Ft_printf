/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oren <orfreoua@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:51:09 by oren              #+#    #+#             */
/*   Updated: 2020/09/29 15:51:12 by oren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*exception(void)
{
	char	*str;

	if (!(str = malloc(2)))
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

int		compt_for_malloc(int n)
{
	int i;

	i = 0;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	swap;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	while (i < j)
	{
		swap = str[i];
		str[i] = str[j - 1];
		str[j - 1] = swap;
		i++;
		j--;
	}
	return (str);
}

char	*fill_the_string(unsigned int nb, int n, char *str, short index)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	if (index == 1 && n < 0)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
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
	str = fill_the_string(nb, n, str, 1);
	str = ft_strrev(str);
	return (str);
}
