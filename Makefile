# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:10:02 by ylabrahm          #+#    #+#              #
#    Updated: 2023/01/19 13:49:21 by ylabrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=server.c client.c 

SRC_O=$(SRC:.c=.o)

SERVER_O=server.o
CLIENT_O=client.o

LIBFT=libft/libft.a

CC=gcc

all: $(SRC_O)
# $(CC) -o server $(SERVER_O) $(LIBFT)
# $(CC) -o client $(CLIENT_O) $(LIBFT)