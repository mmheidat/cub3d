/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:17:48 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 19:18:55 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_fork(char *src, int from, int to)
{
	int		i;
	char	*copy;

	copy = malloc(sizeof(char) * ((to - from) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < (to - from))
	{
		copy[i] = src[from + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
