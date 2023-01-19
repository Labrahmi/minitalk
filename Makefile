# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:10:02 by ylabrahm          #+#    #+#              #
#    Updated: 2023/01/19 16:21:39 by ylabrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=client server

SRCS=client.c server.c

OBJS=$(SRCS:.c=.o)

CC=cc

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) client.o libft/libft.a -o client
	$(CC) server.o libft/libft.a -o server