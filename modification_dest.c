/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modification_dest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 22:08:31 by oren              #+#    #+#             */
/*   Updated: 2020/11/03 04:15:28 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*with_charc_after(char *arg, int number, char c)
{
	char	*dest;
	int		i;

	if (ft_strlen(arg) < number)
	{
		dest = malloc(sizeof(char) * number + 1);
		i = 0;
		while (arg[i])
		{
			dest[i] = arg[i];
			i++;
		}
		number -= i;
		while (number > 0)
		{
			dest[i] = c;
			i++;
			number--;
		}
		dest[i] = 0;
		return (dest);
	}
	if (!(dest = ft_strdup(arg)))
		return (0);
	return (dest);
}

char	*file_with_charc_before(int number, char c, char *arg)
{
	int		i;
	int		j;
	char	*dest;

	if (!(dest = malloc(sizeof(char) * number + 1)))
		return (0);
	number -= ft_strlen(arg);
	i = 0;
	while (number > 0)
	{
		dest[i] = c;
		i++;
		number--;
	}
	j = 0;
	while (arg[j])
	{
		dest[i + j] = arg[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*with_charc_before(char *arg, int number, char c)
{
	char	*dest;

	if (ft_strlen(arg) >= number)
	{
		if (!(dest = ft_strdup(arg)))
			return (0);
		return (dest);
	}
	dest = file_with_charc_before(number, c, arg);
	return (dest);
}

int		have_point_in_str(char *str, int number)
{
	static char	*arg = "csdiuxX%";
	int			i;

	i = number;
	while (str[i])
	{
		if (find_index(str[i], arg) != -1)
			break ;
		i++;
	}
	while (number < i)
	{
		if (str[number] == '.')
			return (number);
		number++;
	}
	return (0);
}
