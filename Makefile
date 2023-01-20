# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:10:02 by ylabrahm          #+#    #+#              #
#    Updated: 2023/01/20 00:25:09 by ylabrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client server

SRCS = client.c server.c

SRCS_BONUS = client_bonus.c server_bonus.c

LIBFT_FILE = libft/libft.a

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

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
	$(RM) $(OBJS_BONUS)
	@make fclean -C libft/

bonus:	$(OBJS_BONUS)
	@make -C libft/
	$(CC) client_bonus.o $(LIBFT_FILE) -o client
	$(CC) server_bonus.o $(LIBFT_FILE) -o server

fclean: clean

re:	fclean all

.PHONY: all clean fclean re