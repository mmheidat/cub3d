/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 01:57:45 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 02:14:39 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_parse_formatters(const char *format, int i, va_list args);
int		ft_putpointer(unsigned long long n);
int		ft_puthexnbr(unsigned int n, int is_upper);
int		ft_putunsigned(unsigned int n);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
#endif