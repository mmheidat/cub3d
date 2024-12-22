/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:11:08 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 03:38:46 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static bool	ft_is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	is_map_line_valid(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			break ;
		i++;
	}
	if (i >= ft_strlen(line))
		return (false);
	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ')
			line[i] = '1';
		if (!ft_is_valid_map_char(line[i]))
			return (false);
	}
	return (true);
}

static bool	ft_is_matrix_valid(t_map map, int *spawn)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < ft_strlen(map.grid[i]))
		{
			if (map.grid[i][j] == 'N' || map.grid[i][j] == 'S' \
				|| map.grid[i][j] == 'E' || map.grid[i][j] == 'W')
				(*spawn)++;
			if (*spawn > 1)
			{
				ft_error("Map contains more than one spawn point (N, S, E, W)");
				return (false);
			}
			if (!ft_is_valid_map_char(map.grid[i][j]))
			{
				ft_error("Map contains invalid characters");
				return (false);
			}
		}
	}
	return (true);
}

bool	validate_map_structure(t_map map)
{
	int	spawn;

	spawn = 0;
	if (!ft_is_matrix_valid(map, &spawn))
		return (false);
	if (spawn == 0)
	{
		ft_error("Map contains no spawn point (N, S, E, W)");
		return (false);
	}
	if (fl_can_exit(map))
	{
		ft_error("Map is not closed");
		return (false);
	}
	return (true);
}

void	locate_player_in_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < ft_strlen(map->grid[i]))
		{
			if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S' \
				|| map->grid[i][j] == 'E' || map->grid[i][j] == 'W')
			{
				map->player_x = i;
				map->player_y = j;
				map->player_dir = map->grid[i][j];
				return ;
			}
		}
	}
}
