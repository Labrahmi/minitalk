# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:10:02 by ylabrahm          #+#    #+#              #
#    Updated: 2023/01/19 19:45:06 by ylabrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client server

SRCS = client.c server.c

LIBFT_FILE = libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	$(CC) client.o $(LIBFT_FILE) -o client
	$(CC) server.o $(LIBFT_FILE) -o server

clean:
	$(RM) $(NAME)
	$(RM) $(OBJS)
	@make fclean -C libft/

fclean: clean

re:	fclean all

.PHONY: all clean fclean re