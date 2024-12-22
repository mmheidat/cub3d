/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 01:22:39 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 19:21:02 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, const char *set)
{
	char	*str;
	size_t	start;
	size_t	stop;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	stop = (size_t) ft_strlen(s1);
	while (s1[start] && ft_is_set(s1[start], set))
		start++;
	while (stop > start && ft_is_set(s1[stop - 1], set))
		stop--;
	str = ft_substr(&s1[start], 0, stop - start);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	mallocable;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t) ft_strlen(s) < start)
		return (ft_strdup(""));
	mallocable = 0;
	if ((size_t) ft_strlen(s) > start)
		mallocable = ft_strlen(s) - start;
	if (mallocable > len)
		mallocable = len;
	str = malloc(sizeof(char) * (mallocable + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		src_len;
	int		i;
	char	*src_cpy;

	src_len = ft_strlen(s1);
	src_cpy = malloc(sizeof(char) * src_len + 1);
	if (!src_cpy)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		src_cpy[i] = s1[i];
		i++;
	}
	src_cpy[i] = '\0';
	return (src_cpy);
}

int	ft_word_count(char const *str, char sep)
{
	int	i;
	int	count;

	if (str == 0 || str[0] == 0)
		return (0);
	i = 1;
	count = 0;
	if (str[0] != sep)
		count++;
	while (str[i] != '\0')
	{
		if (str[i] != sep && str[i - 1] == sep)
			count++;
		i++;
	}
	return (count);
}
