# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:10:02 by ylabrahm          #+#    #+#              #
#    Updated: 2023/01/18 21:01:48 by ylabrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

SRC = client.c server.c

OBJS = $(SRC:.c=.o)

LIBFT = libft/libft.a

CC = cc

RM = rm -f

# CFLAGS = -Wall -Wextra -Werror 

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o server server.o $(LIBFT)