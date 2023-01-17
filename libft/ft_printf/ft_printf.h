/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 00:27:07 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/10/25 01:02:13 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *ch, ...);
int		ft_print_char(char c);
void	ft_print_int_(int i, int *ip);
void	ft_print_uint(unsigned int ui, int *ip);
int		ft_print_str_(char *cp);
void	ft_print_hexl(unsigned int ul, int *ip, char c);
void	ft_print_hexp(unsigned long ul, int *ip);

#endif