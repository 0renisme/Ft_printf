/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_minus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 00:14:06 by oren              #+#    #+#             */
/*   Updated: 2020/11/03 04:28:02 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_char_and_string(char *arg, int *value, char sign, char pos)
{
	char	*temp;
	char	*dest;

	if (pos == 's' && sign == '.')
	{
		if (value[1] < 0)
			value[1] = ft_strlen(arg);
		temp = ft_substr(arg, 0, value[1]);
		dest = with_charc_after(temp, value[0], ' ');
		free(temp);
	}
	else
		dest = with_charc_after(arg, value[0], ' ');
	free(arg);
	return (dest);
}

char	*fill_pointer(char *arg, int *value, char sign)
{
	char	*temp;
	char	*temp1;
	char	*dest;

	if (ft_strlen(arg) == 3 && value[1] == 0 && sign == '.')
	{
		temp = "0x";
		dest = with_charc_after(temp, value[0], ' ');
	}
	temp = ft_substr(arg, 2, ft_strlen(arg));
	value[0] -= 2;
	temp1 = with_charc_before(temp, value[1], '0');
	free(temp);
	temp = with_charc_after(temp1, value[0], ' ');
	dest = ft_strjoin("0x", temp);
	free(arg);
	free(temp1);
	return (dest);
}

char	*minus_before(char *arg, int *value)
{
	char	*temp;
	char	*temp2;
	char	*dest;

	if (!(temp = ft_substr(arg, 1, ft_strlen(arg))))
		return (0);
	temp2 = with_charc_before(temp, value[1], '0');
	free(temp);
	temp = ft_strjoin("-", temp2);
	dest = with_charc_after(temp, value[0], ' ');
	free(temp);
	free(arg);
	return (dest);
}

char	*fill_dest_minus(char *arg, int *value, char sign)
{
	char	*dest;
	char	*temp;

	if (arg[0] == '-')
		return (minus_before(arg, value));
	else
	{
		if (value[1] == 0 && arg[0] == '0' && sign == '.')
			dest = with_charc_after("", value[0], ' ');
		else
		{
			if (value[1] < 0)
				value[1] = 0;
			temp = with_charc_before(arg, value[1], '0');
			dest = with_charc_after(temp, value[0], ' ');
			free(temp);
		}
	}
	free(arg);
	return (dest);
}

char	*minus(va_list *my_list, char *str, int i)
{
	int		value[2];
	char	*arg;
	char	sign;

	sign = 0;
	if (!(check_error_minus(str, i)))
		return (0);
	i = pass_zero_and_minus(str, i);
	value[0] = value_after_point(my_list, str, i);
	if (value[0] < 0)
		value[0] = -value[0];
	while (str[i] == '*' || ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		sign = '.';
		i++;
	}
	value[1] = value_after_point(my_list, str, i);
	while (str[i] == '*' || ft_isdigit(str[i]))
		i++;
	if (!(arg = tab_fonction(my_list, str, i - 1)))
		return (0);
	return (redirect(arg, value, sign, str[i]));
}
