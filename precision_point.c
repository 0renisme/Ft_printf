/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:57:11 by oren              #+#    #+#             */
/*   Updated: 2020/11/01 13:36:40 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*with_right_part_arg(char *arg, int nb_after)
{
	char *temp;
	char *temp2;
	char *dest;

	if (nb_after == 0 && arg[0] == '0')
	{
		if (!(dest = ft_strdup("")))
			return (0);
		return (dest);
	}
	if (arg[0] == '-')
	{
		if (!(temp = ft_substr(arg, 1, ft_strlen(arg))))
			return (0);
		if (!(temp2 = with_charc_before(temp, nb_after, '0')))
			return (0);
		free(temp);
		if (!(dest = ft_strjoin("-", temp2)))
			return (0);
		return (dest);
	}
	if (!(dest = with_charc_before(arg, nb_after, '0')))
		return (0);
	return (dest);
}

char	*arg_with_right_part(int nb_after, char c, char *arg)
{
	char	*dest;
	int		index;

	index = find_index(c, "diuxXs%cp");
	if (index < 5)
	{
		if (!(dest = with_right_part_arg(arg, nb_after)))
			return (0);
	}
	else if (index == 5)
	{
		if (!(dest = ft_substr(arg, 0, nb_after)))
			return (0);
	}
	else
	{
		if (!(dest = ft_strdup(arg)))
			return (0);
	}
	return (dest);
}

char	*fill_dest(char *arg, int nb_before, int nb_after, char c)
{
	char		*temp;
	char		*dest;

	if (c == 'p' && ft_strlen(arg) == 3)
	{
		free(arg);
		if (!(arg = ft_strdup("0x")))
			return (0);
	}
	if (nb_after < 0 && c == 's')
		nb_after = ft_strlen(arg);
	if ((arg[0] == '-') && (c == 'd' || c == 'i') && (nb_after == 0) &&
	(nb_before >= 0))
		nb_after--;
	temp = arg_with_right_part(nb_after, c, arg);
	free(arg);
	if (nb_before < 0)
	{
		nb_before = -nb_before;
		dest = with_charc_after(temp, nb_before, ' ');
	}
	else
		dest = with_charc_before(temp, nb_before, ' ');
	free(temp);
	return (dest);
}

short	is_zero_before(char *str, int i)
{
	while (str[i] != '%')
		i--;
	if (str[i + 1] == '0')
		return (1);
	return (0);
}

char	*point(va_list *my_list, char *str, int i)
{
	int		value_before;
	int		value_after;
	char	*dest;
	char	*arg;

	if ((check_before_point(str, i - 1) + check_after_point(str, i + 1)) != 2)
		return (0);
	value_before = value_before_point(my_list, str, (i - 1));
	value_after = value_after_point(my_list, str, (i + 1));
	while ((ft_isdigit(str[i + 1]) || (str[i + 1] == '*')))
		i++;
	if (!(arg = tab_fonction(my_list, str, i)))
		return (0);
	if (is_zero_before(str, i) && value_after < 0 && value_before > 0)
	{
		if (arg[0] == '-' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
			value_after = value_before - 1;
		else
			value_after = value_before;
		value_before = 0;
	}
	dest = fill_dest(arg, value_before, value_after, str[i + 1]);
	return (dest);
}
