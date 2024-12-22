/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 02:00:58 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 19:12:10 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putstr("-2147483648");
		return (i);
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

static int	ft_printpointer(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_printpointer(n / 16);
		i += ft_printpointer(n % 16);
	}
	else
	{
		if (n < 10)
			i += ft_putchar(n + '0');
		else
			i += ft_putchar(n + 'a' - 10);
	}
	return (i);
}

int	ft_putpointer(unsigned long long n)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_printpointer(n);
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putunsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putunsigned(n / 10);
		i += ft_putunsigned(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}
