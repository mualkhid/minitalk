/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:02:08 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/04 11:02:09 by mualkhid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

void	ft_ch(char c, int *len);
void	ft_str(char *s, int *len);
void	ft_putnum(int n, int *len);
void	ft_pointer(unsigned long pointer, int *length);
void	ft_hexa(unsigned int x, int *len, char x_or_X);
void	ft_unsigned_int(unsigned int u, int *len);
int		ft_printf(const char *string, ...);

#endif
