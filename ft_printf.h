/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:02:38 by orfreoua          #+#    #+#             */
/*   Updated: 2020/11/03 04:20:02 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		free_error(char *s1, char *s2);
char	*fill_temp(va_list *my_list, char *str, int i);
char	*character(va_list *my_list, char *str, int i);
char	*string(va_list *my_list, char *str, int i);
char	*pointer(va_list *my_list, char *str, int i);
char	*percent(va_list *my_list, char *str, int i);
char	*integer(va_list *my_list, char *str, int i);
char	*integerr(va_list *my_list, char *str, int i);
char	*unsigned_integer(va_list *my_list, char *str, int i);
char	*hexa_min(va_list *my_list, char *str, int i);
char	*hexa_maj(va_list *my_list, char *str, int i);
char	*digital(va_list *my_list, char *str, int i);
char	*minus(va_list *my_list, char *str, int i);
char	*point(va_list *my_list, char *str, int i);
int		value_before_point(va_list *my_list, char *str, int i);
int		value_after_point(va_list *my_list, char *str, int i);
int		check_before_point(char *str, int i);
int		check_after_point(char *str, int i);
char	*star(va_list *my_list, char *str, int i);
char	*zero(va_list *my_list, char *str, int i);
short	zero_and_minus(char *str, int i);
int		pass_zero_and_minus(char *str, int i);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *str, int start, int end);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
char	*ft_itoa_unsigned(size_t n);
char	*ft_strrev(char *str);
int		compt_for_malloc(int n);
char	*exception(void);
char	*ft_itoa_base(unsigned int n, char *base);
int		ft_atoi(const char *str);
int		my_atoi_substr(char *str, int i);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
char	*with_charc_after(char *arg, int number, char c);
char	*with_charc_before(char *arg, int number, char c);
char	*tab_fonction(va_list *my_list, char *str, int i);
int		find_index(char c, char *index_tab);
int		good_position(char *str, int i);
int		up_to_the_percent_sign(char *str, int i);
int		have_point_in_str(char *str, int number);
char	*fill_the_string(unsigned int nb, int n, char *str, short index);
short	is_good_point(char *str, int i);
char	*ft_itoa_long_base(unsigned long int n, char *base);
short	is_string_b(char *str, int i, char a, char b);
char	*redirect(char *arg, int *value, char sign, char pos);
short	check_error_minus(char *str, int i);
char	*fill_char_and_string(char *arg, int *value, char sign, char pos);
char	*fill_pointer(char *arg, int *value, char sign);
char	*fill_dest_minus(char *arg, int *value, char sign);

#endif
