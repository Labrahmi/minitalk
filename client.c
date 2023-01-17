/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:56 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/17 18:50:25 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

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

void	ft_set_to_zeros(unsigned char *array)
{
	int	i;

	while (i < 8)
		array[i++] = '0';
}

void	ft_print_bin(int pid ,unsigned char num)
{
	int				i;
	unsigned char	array[8];
	unsigned char	temp_num;
	
	ft_set_to_zeros(array);
	temp_num = num;
	i = 0;
	while (temp_num)
	{
		array[i++] = (temp_num % 2) + '0';
		temp_num /= 2;
	}
	i = 0;
	while (i < 8)
	{
		if (array[i] == '0')
			kill(pid, SIGUSR1);
		if (array[i] == '1')
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	if (argc == 3)
	{
		unsigned char C = 0b01000011;
		ft_print_bin(atoi(argv[1]), argv[2][0]);
	}
	return 0;
}
