/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:11:52 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/21 21:39:19 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(100);
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

int	main(int argc, char *argv[])
{
	int				i;
	unsigned char	*string;

	if (ft_atoi(argv[1]) <= 1)
		exit(1);
	if (argc == 3)
	{
		signal(SIGUSR1, sigint_handler);
		string = (unsigned char *) argv[2];
		i = 0;
		while (string[i])
		{
			ft_print_bin(string[i], ft_atoi(argv[1]));
			i++;
		}
		ft_print_bin(0, ft_atoi(argv[1]));
	}
	return (0);
}
