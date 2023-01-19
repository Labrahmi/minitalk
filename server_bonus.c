/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:11:41 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/20 00:11:48 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

int	g_received[8];

void	ft_set_to_zeros(int *array)
{
	int	i;

	i = 0;
	while (i < 8)
		array[i++] = 0;
}

int	ft_pow(int n, int p)
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

int	check_end_stream(int *array)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (array[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

void	sigint_handler(int sig, siginfo_t *info, void *context)
{
	static pid_t	client_pid;
	static int		i;
	int				c;

	if (!(client_pid))
		client_pid = info->si_pid;
	if (client_pid != info->si_pid)
	{
		i = 0;
		ft_set_to_zeros(g_received);
		client_pid = 0;
	}
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
		if (check_end_stream(g_received))
		{
			usleep(100);
			kill(client_pid, SIGUSR1);
		}
	}
}

int	main(void)
{
	int					server_pid;
	struct sigaction	action;

	server_pid = getpid();
	ft_printf("%d\n", server_pid);
	action.sa_sigaction = sigint_handler;
	action.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}
