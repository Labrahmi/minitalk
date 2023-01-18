/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:53 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/18 15:06:59 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

int	g_received[8];

void	ft_set_to_zeros(int *array)
{
	int	i;

	while (i < 8)
		array[i++] = 0;
}

int	ft_pow(n, p)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (i < p)
	{
		res *= n;
		i++;
	}
	return (res);
}

void	ft_bin_to_dec(int *rev)
{
	int	some;
	int	i;

	some = 0;
	i = 0;
	while (i < 8)
	{
		some += (rev[i]) * ft_pow(2, i);
		i++;
	}
	ft_printf("%c", some);
}

void	sigint_handler(int sig)
{
	static int	i;
	int			j;
	int			c;

	ft_set_to_zeros(g_received);
	if (sig == SIGUSR1)
		c = 0;
	if (sig == SIGUSR2)
		c = 1;
	g_received[i] = c;
	i++;
	if (i == 8)
	{
		i = 0;
		ft_bin_to_dec(g_received);
	}
}

int main(int argc, char const *argv[])
{
	int server_pid;

	server_pid = getpid();
	ft_printf("%d\n", server_pid);
	signal(SIGUSR1, sigint_handler);
	signal(SIGUSR2, sigint_handler);
	while (1)
		pause();
	return 0;
}
