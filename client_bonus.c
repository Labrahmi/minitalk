/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:11:52 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/20 01:19:52 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	ft_set_to_zeros(int *array)
{
	int	i;

	i = 0;
	while (i < 8)
		array[i++] = 0;
}

void	ft_print_bin(unsigned char num, int pid)
{
	int				i;
	int				array[8];
	unsigned char	temp_num;

	ft_set_to_zeros(array);
	temp_num = num;
	i = 0;
	while (temp_num)
	{
		array[i++] = (temp_num % 2);
		temp_num /= 2;
	}
	i = 0;
	while (i < 8)
	{
		if (array[i] == 0)
			kill(pid, SIGUSR1);
		if (array[i] == 1)
			kill(pid, SIGUSR2);
		usleep(1000);
		i++;
	}
}

void	sigint_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("message received\n");
		exit(0);
	}
}

int	main(int argc, const char *argv[])
{
	int				i;
	unsigned char	*string;

	if (argc == 3)
	{
		string = (char *) argv[2];
		i = 0;
		while (string[i])
		{
			ft_print_bin(string[i], ft_atoi(argv[1]));
			i++;
		}
		ft_print_bin(0, ft_atoi(argv[1]));
		while (1)
		{
			signal(SIGUSR1, sigint_handler);
			pause();
		}
	}
	return (0);
}