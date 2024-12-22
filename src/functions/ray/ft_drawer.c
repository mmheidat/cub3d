/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:11:08 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 03:38:30 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	ft_draw_floor_ceiling(t_cub *cub, int x, int from)
{
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		if (y <= from)
			my_mlx_pixel_put(cub, x, y, cub->textures.ceiling);
		else
			my_mlx_pixel_put(cub, x, y, cub->textures.floor);
	}
}

static void	ft_apply_texture(t_cub *cub, int direction, int x)
{
	int	color;

	color = ft_grab_pixel_rgb(&cub->textures.mlx_textures[direction], \
		cub->raycast.tex_x, cub->raycast.tex_y);
	my_mlx_pixel_put(cub, x, cub->raycast.draw_start, color);
}

static void	ft_calc_tex_positions(t_cub *cub)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	if (!ray->side_hit)
		ray->tex_wall_x = cub->player.y + ray->wall_dist \
			* ray->ray_y;
	else
		ray->tex_wall_x = cub->player.x + ray->wall_dist \
			* ray->ray_x;
	ray->tex_wall_x -= floor(ray->tex_wall_x);
	ray->tex_x = ray->tex_wall_x * TEX_WIDTH;
	if (!ray->side_hit && ray->ray_x > 0)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
	if (ray->side_hit && ray->ray_y < 0)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
	ray->tex_step = 1.0 * TEX_HEIGHT / ray->line_height;
	ray->tex_pos = (ray->draw_start - HEIGHT / 2 \
		+ ray->line_height / 2) * ray->tex_step;
}

void	ft_textures(t_cub *cub, int x)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	ft_calc_tex_positions(cub);
	ft_draw_floor_ceiling(cub, x, ray->draw_start);
	while (ray->draw_start++ < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
		ray->tex_pos += ray->tex_step;
		if (!ray->side_hit && cub->player.x < ray->map_x)
			ft_apply_texture(cub, SOUTH_DIRECTION, x);
		else if (!ray->side_hit && cub->player.x > ray->map_x)
			ft_apply_texture(cub, NORTH_DIRECTION, x);
		else if (ray->side_hit && cub->player.y < ray->map_y)
			ft_apply_texture(cub, EAST_DIRECTION, x);
		else if (ray->side_hit && cub->player.y > ray->map_y)
			ft_apply_texture(cub, WEST_DIRECTION, x);
	}
}
