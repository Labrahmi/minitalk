/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:53 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/17 18:46:37 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <math.h>

unsigned char	received[8];

// 01000001
// 10000010


void	ft_bin_to_dec(unsigned char *rev)
{
	int	some;
	int	i;

	some = 0;
	i = 0;
	while (i < 8)
	{
		some += (rev[i] - '0') * pow(2, i);
		i++;
	}
	printf("%c\n", some);
}

void	sigint_handler(int sig)
{
	unsigned char	c;
	static int		i;
	int				j;

	if (sig == SIGUSR1)
		c = '0';
	if (sig == SIGUSR2)
		c = '1';
	received[i] = c;
	i++;
	if (i == 8)
	{
		i = 0;
		ft_bin_to_dec(received);
	}
}

int main(int argc, char const *argv[])
{
	int server_pid;

	server_pid = getpid();
	printf("%d\n", server_pid);
	signal(SIGUSR1, sigint_handler);
	signal(SIGUSR2, sigint_handler);
	while (1)
		pause();
	return 0;
}
