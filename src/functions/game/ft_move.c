/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:40:01 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 16:43:58 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static bool	ft_is_wall(float x, float y, t_cub *cub)
{
	char	**worldmap;

	if (!cub->map.grid)
		ft_error("map not found");
	worldmap = cub->map.grid;
	if (worldmap[(int)x][(int)y] == '1')
		return (true);
	return (false);
}

void	ft_move_up_down(int keycode, t_cub *cub)
{
	if (keycode == W)
	{
		if (!ft_is_wall(cub->player.x + cub->player.dir_x * \
				(MOVE_SPEED + 0.1), cub->player.y, cub))
			cub->player.x += cub->player.dir_x * MOVE_SPEED;
		if (!ft_is_wall(cub->player.x, cub->player.y + \
				cub->player.dir_y * (MOVE_SPEED + 0.1), cub))
			cub->player.y += cub->player.dir_y * MOVE_SPEED;
	}
	if (keycode == S)
	{
		if (!ft_is_wall(cub->player.x - cub->player.dir_x * \
				(MOVE_SPEED + 0.1), cub->player.y, cub))
			cub->player.x -= cub->player.dir_x * MOVE_SPEED;
		if (!ft_is_wall(cub->player.x, cub->player.y - \
				cub->player.dir_y * (MOVE_SPEED + 0.1), cub))
			cub->player.y -= cub->player.dir_y * MOVE_SPEED;
	}
}

void	ft_move_left_right(int keycode, t_cub *cub)
{
	if (keycode == A)
	{
		if (!ft_is_wall(cub->player.x - cub->player.dir_y * \
				(MOVE_SPEED + 0.1), cub->player.y, cub))
			cub->player.x -= cub->player.dir_y * MOVE_SPEED;
		if (!ft_is_wall(cub->player.x, cub->player.y + \
				cub->player.dir_x * (MOVE_SPEED + 0.1), cub))
			cub->player.y += cub->player.dir_x * MOVE_SPEED;
	}
	if (keycode == D)
	{
		if (!ft_is_wall(cub->player.x + cub->player.dir_y * \
				(MOVE_SPEED + 0.1), cub->player.y, cub))
			cub->player.x += cub->player.dir_y * MOVE_SPEED;
		if (!ft_is_wall(cub->player.x, cub->player.y - \
				cub->player.dir_x * (MOVE_SPEED + 0.1), cub))
			cub->player.y -= cub->player.dir_x * MOVE_SPEED;
	}
}

void	ft_move_rotate(int keycode, t_cub *cub)
{
	cub->player.old_dir_x = cub->player.dir_x;
	cub->player.old_plane_x = cub->player.plane_x;
	if (keycode == LEFT)
	{
		cub->player.dir_x = cub->player.dir_x * cos(ROT_SPEED) - \
			cub->player.dir_y * sin(ROT_SPEED);
		cub->player.dir_y = cub->player.old_dir_x * sin(ROT_SPEED) + \
			cub->player.dir_y * cos(ROT_SPEED);
		cub->player.plane_x = cub->player.plane_x * cos(ROT_SPEED) - \
			cub->player.plane_y * sin(ROT_SPEED);
		cub->player.plane_y = cub->player.old_plane_x * sin(ROT_SPEED) + \
			cub->player.plane_y * cos(ROT_SPEED);
	}
	if (keycode == RIGHT)
	{
		cub->player.dir_x = cub->player.dir_x * cos(-ROT_SPEED) - \
			cub->player.dir_y * sin(-ROT_SPEED);
		cub->player.dir_y = cub->player.old_dir_x * sin(-ROT_SPEED) + \
			cub->player.dir_y * cos(-ROT_SPEED);
		cub->player.plane_x = cub->player.plane_x * cos(-ROT_SPEED) - \
			cub->player.plane_y * sin(-ROT_SPEED);
		cub->player.plane_y = cub->player.old_plane_x * sin(-ROT_SPEED) + \
			cub->player.plane_y * cos(-ROT_SPEED);
	}
}
