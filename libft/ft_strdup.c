/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:12:51 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/10/21 12:01:27 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret_pointer;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	ret_pointer = (char *) ft_calloc((len + 1), sizeof(char));
	if (!ret_pointer)
		return (NULL);
	while (s1[i] != '\0')
	{
		ret_pointer[i] = s1[i];
		i++;
	}
	return (ret_pointer);
}
