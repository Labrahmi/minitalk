# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 23:46:47 by ylabrahm          #+#    #+#              #
#    Updated: 2022/10/25 00:07:04 by ylabrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRC = ft_printf.c \
	sources/ft_print_char.c sources/ft_print_hexl.c \
	sources/ft_print_int_.c sources/ft_print_str_.c \
	sources/ft_print_uint.c sources/ft_print_hexp.c

OBJ = $(SRC:.c=.o)

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) *.o
	$(RM) */*.o

fclean:	clean
	$(RM) *.a

re: fclean all
