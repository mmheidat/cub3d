/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 01:59:11 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 02:00:51 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_parse_formatters(const char *format, int i, va_list args)
{
	int	count;

	count = 0;
	if (format[i] != '%')
	{
		if (format[i] == 's')
			count += ft_putstr(va_arg(args, char *));
		else if (format[i] == 'd' || format[i] == 'i')
			count += ft_putnbr(va_arg(args, int));
		else if (format[i] == 'c')
			count += ft_putchar(va_arg(args, int));
		else if (format[i] == 'u')
			count += ft_putunsigned(va_arg(args, unsigned int));
		else if (format[i] == 'x')
			count += ft_puthexnbr(va_arg(args, unsigned int), 0);
		else if (format[i] == 'X')
			count += ft_puthexnbr(va_arg(args, unsigned int), 1);
		else if (format[i] == 'p')
			count += ft_putpointer(va_arg(args, unsigned long long));
		else
			count += ft_putchar(format[i]);
	}
	else
		count += ft_putchar(format[i]);
	return (count);
}

int	ft_puthexnbr(unsigned int n, int is_upper)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_puthexnbr(n / 16, is_upper);
		i += ft_puthexnbr(n % 16, is_upper);
	}
	else
	{
		if (n < 10)
			i += ft_putchar(n + '0');
		else
		{
			if (is_upper)
				i += ft_putchar(ft_toupper(n + 'a' - 10));
			else
				i += ft_putchar(ft_tolower(n + 'a' - 10));
		}
	}
	return (i);
}
