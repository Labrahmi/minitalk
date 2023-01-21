/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:56 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/21 21:50:30 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_bin(char num, int pid)
{
	int	i;
	int	array[8];
	int	temp_num;

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

int	main(int argc, const char *argv[])
{
	int		i;
	char	*string;

	if (argc == 3)
	{
		if (ft_atoi(argv[1]) <= 1)
			exit(1);
		string = (char *) argv[2];
		i = 0;
		while (string[i])
		{
			ft_print_bin(string[i], ft_atoi(argv[1]));
			i++;
		}
	}
	return (0);
}
