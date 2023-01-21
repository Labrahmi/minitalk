# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:10:02 by ylabrahm          #+#    #+#              #
#    Updated: 2023/01/21 21:00:33 by ylabrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client server

NAME_BONUS = client_bonus server_bonus

SRCS = client.c server.c minitalk_utils.c

SRCS_BONUS = client_bonus.c server_bonus.c minitalk_utils.c

LIBFT_FILE = libft/libft.a

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	$(CC) client.o minitalk_utils.o $(LIBFT_FILE) -o client
	$(CC) server.o minitalk_utils.o $(LIBFT_FILE) -o server

clean: clean_libft
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re:	fclean all

bonus:	make_libft server_bonus client_bonus

server_bonus: $(OBJS_BONUS) 
	$(CC) server_bonus.o minitalk_utils.o $(LIBFT_FILE) -o server_bonus

client_bonus: $(OBJS_BONUS) 
	$(CC) client_bonus.o minitalk_utils.o $(LIBFT_FILE) -o client_bonus

make_libft:
	@make -C libft/

clean_libft:
	@make fclean -C libft/

.PHONY: all clean fclean re bonus