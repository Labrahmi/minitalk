/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:53 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/21 20:17:53 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_received[8];

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

void	sigint_handler(int sig, siginfo_t *info, void *context)
{
	static pid_t	client_pid;
	static int		i;
	int				c;

	(void) context;
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
