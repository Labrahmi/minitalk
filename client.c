/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:56 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/17 23:18:33 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

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

void	ft_print_bin(char num, int pid)
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
		usleep(10);
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