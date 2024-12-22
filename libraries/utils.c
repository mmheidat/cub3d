/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 01:14:52 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 19:20:47 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*_s1;
	unsigned char	*_s2;

	i = 0;
	_s1 = (unsigned char *) s1;
	_s2 = (unsigned char *) s2;
	while (n--)
	{
		if (!_s1[i] || !_s2[i] || _s1[i] != _s2[i])
			return (_s1[i] - _s2[i]);
		i++;
	}
	return (0);
}

char	**ft_strsjoin(char **grid, char *new_line)
{
	int		i;
	char	**new_grid;

	i = 0;
	if (!grid || !new_line)
		return (NULL);
	while (grid[i])
		i++;
	new_grid = malloc(sizeof(char *) * (i + 2));
	if (!new_grid)
		return (NULL);
	i = 0;
	while (grid[i])
	{
		new_grid[i] = grid[i];
		i++;
	}
	new_grid[i] = new_line;
	new_grid[i + 1] = NULL;
	free(grid);
	return (new_grid);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	i;

	if (size && SIZE_MAX / size < count)
		return (NULL);
	pointer = (void *) malloc(count * size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		*(unsigned char *)(pointer + i) = 0;
		i++;
	}
	return (pointer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
