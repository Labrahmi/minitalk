# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:10:02 by ylabrahm          #+#    #+#              #
#    Updated: 2023/01/17 22:23:00 by ylabrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client

NAME_S = server

LIBFT = libft/libft.a

FT_PRINTF = libft/ft_printf/libftprintf.a

MAKE_LIBFT = make -C libft/

MAKE_PRINTF = make -C libft/ft_printf/

CC = cc

all:
	$(MAKE_LIBFT)
	$(MAKE_PRINTF)
	$(CC) -o $(NAME_C) client.c $(LIBFT) $(FT_PRINTF)
	$(CC) -o $(NAME_S) server.c $(LIBFT) $(FT_PRINTF)
	
clean:
	rm -f $(NAME_C) $(NAME_S)
	make fclean -C libft/
	make fclean -C libft/ft_printf/

fclean:	clean