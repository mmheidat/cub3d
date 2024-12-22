/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:11:08 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 16:30:23 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static t_map	ft_init_map(void)
{
	t_map	map;

	map.grid = ft_calloc(1, sizeof(char *));
	map.height = 0;
	map.width = 0;
	if (!map.grid)
		ft_error("malloc error");
	return (map);
}

static void	ft_fill_matrix(t_map *map, int fd)
{
	char		*line;
	bool		reading_map;

	reading_map = false;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = ft_free_to_trim(line, "\t\n");
		if (is_map_line_valid(line))
		{
			reading_map = true;
			map->grid = ft_strsjoin(map->grid, ft_strdup(line));
			if (ft_strlen(line) > map->width)
				map->width = ft_strlen(line);
			map->height++;
		}
		else if (reading_map)
		{
			free(line);
			ft_error("invalid map");
		}
		free(line);
	}
}

static void	ft_normalise_width(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = ft_strlen(map.grid[i]);
		while (j < map.width)
		{
			map.grid[i] = ft_join_and_free(map.grid[i], "1");
			j++;
		}
		i++;
	}
}

t_map	parse_map_from_file(char *path)
{
	int			fd;
	t_map		map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("file not found");
	map = ft_init_map();
	ft_fill_matrix(&map, fd);
	close(fd);
	validate_map_structure(map);
	ft_normalise_width(map);
	locate_player_in_map(&map);
	return (map);
}
