CC = gcc
NAME = libftprintf.a
 SRC =	ft_printf.c \
 		ft_printf_utils.c \
 		libft_file.c \
 		arg_ascii.c \
 		arg_digit.c \
 		ft_atoi.c \
 		ft_itoa.c \
 		ft_itoa_base.c \
 		ft_itoa_unsigned.c \
 		modification_dest.c \
 		precision_digital.c \
 		precision_minus.c \
 		precision_point.c \
 		precision_stars.c \
 		precision_zero.c \
		check_point.c \
		check_minus.c \

OBJ = $(SRC:.c=.o)
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc libftprintf.a $(OBJ)
	ranlib libftprintf.a

clean: 
	rm -rf *.o

fclean: clean
	rm -rf libftprintf.a
re: fclean all