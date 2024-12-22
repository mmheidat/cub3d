/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:11:08 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 03:37:31 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	ft_assign_player_dir(t_player *player, int direction)
{
	if (direction == NORTH_DIRECTION)
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_y = 0.66;
	}
	else if (direction == SOUTH_DIRECTION)
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_y = -0.66;
	}
	else if (direction == EAST_DIRECTION)
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = 0.66;
	}
	else if (direction == WEST_DIRECTION)
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = -0.66;
	}
}

static t_player	ft_init_player(t_map map)
{
	t_player	player;

	player.plane_x = 0;
	player.plane_y = 0;
	if (map.player_dir == 'N')
		ft_assign_player_dir(&player, NORTH_DIRECTION);
	else if (map.player_dir == 'S')
		ft_assign_player_dir(&player, SOUTH_DIRECTION);
	else if (map.player_dir == 'E')
		ft_assign_player_dir(&player, EAST_DIRECTION);
	else if (map.player_dir == 'W')
		ft_assign_player_dir(&player, WEST_DIRECTION);
	player.x = map.player_x + 0.5;
	player.y = map.player_y + 0.5;
	player.old_dir_x = 0;
	player.old_plane_x = 0;
	return (player);
}

static t_mlx	ft_init_mlx(char *filepath)
{
	t_mlx	mlx;
	char	*title;

	title = ft_strjoin("mheid & Fakih cub3D - ", filepath);
	if (!title)
		ft_error("title malloc failed");
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		ft_error("mlx_init failed");
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, title);
	if (!mlx.win)
		ft_error("mlx_new_window failed");
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	if (!mlx.img)
		ft_error("mlx_new_image failed");
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, \
		&mlx.line_len, &mlx.endian);
	if (!mlx.addr)
		ft_error("mlx_get_data_addr failed");
	free(title);
	return (mlx);
}

static t_raycast	ft_init_raycast(void)
{
	t_raycast	ray;

	ray.ray_x = 0;
	ray.ray_y = 0;
	ray.line_height = 0;
	ray.draw_start = 0;
	ray.draw_end = 0;
	ray.map_x = 0;
	ray.map_y = 0;
	ray.tex_x = 0;
	ray.tex_y = 0;
	ray.tex_step = 0;
	ray.tex_pos = 0;
	ray.tex_wall_x = 0;
	ray.side_dist_x = 0;
	ray.side_dist_y = 0;
	ray.delta_dist_x = 0;
	ray.delta_dist_y = 0;
	ray.wall_dist = 0;
	ray.step_x = 0;
	ray.step_y = 0;
	ray.side_hit = false;
	ray.wall_hit = false;
	return (ray);
}

t_cub	*ft_cub3d_init(char *filepath)
{
	t_cub	*cub;

	cub = ft_calloc(1, sizeof(t_cub));
	if (!cub)
		ft_error("struct cub3d malloc failed");
	cub->mlx = ft_init_mlx(filepath);
	cub->textures = parse_textures_from_file(cub, filepath);
	cub->map = parse_map_from_file(filepath);
	cub->player = ft_init_player(cub->map);
	cub->raycast = ft_init_raycast();
	cub->filepath = filepath;
	return (cub);
}
