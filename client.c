/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:56 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/19 01:14:25 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	ft_reverse_array(unsigned char *array)
{
	unsigned char temp;
	int	i;
	int	j;
	int	k;

	k = 4;
	i = 0;
	j = 7;
	while (k > 0)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
		k--;
	}
}

void	ft_set_to_zeros(int *array)
{
	int	i;

	while (i < 8)
		array[i++] = 0;
}

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
		usleep(10000);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	int		i;
	char	*string;
	if (argc == 3)
	{
		string = (char *) argv[2];
		while (string[i])
		{
			ft_print_bin(string[i] , ft_atoi(argv[1]));
			i++;
		}
	}
	return 0;
}
