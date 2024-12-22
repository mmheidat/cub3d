/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:11:08 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 16:41:43 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	fl_find_player(t_map map, int *sr, int *sc)
{
	int	i;
	int	j;

	*sr = -1;
	*sc = -1;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (j < (int)ft_strlen(map.grid[i])
				&& (map.grid[i][j] == 'N' || map.grid[i][j] == 'S'
				|| map.grid[i][j] == 'E' || map.grid[i][j] == 'W'))
			{
				*sr = i;
				*sc = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

bool	has_visited_boundary(bool **visited, t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		if (visited[i][0] || visited[i][map.width - 1])
			return (true);
		i++;
	}
	j = 0;
	while (j < map.width)
	{
		if (visited[0][j] || visited[map.height - 1][j])
			return (true);
		j++;
	}
	return (false);
}

void	free_visited_matrix(bool **visited, t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
