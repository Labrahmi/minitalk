/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:03:28 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/03/05 18:10:26 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
