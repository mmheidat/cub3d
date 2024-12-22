/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:11:08 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 03:38:32 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	ft_init_ray_directions(t_cub *cub, int x)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	ray->ray_x = cub->player.dir_x + cub->player.plane_x * \
		(2 * x / (double)WIDTH - 1);
	ray->ray_y = cub->player.dir_y + cub->player.plane_y * \
		(2 * x / (double)WIDTH - 1);
	ray->map_x = (int) cub->player.x;
	ray->map_y = (int) cub->player.y;
	if (ray->ray_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = absolute_value(1 / ray->ray_x);
	if (ray->ray_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = absolute_value(1 / ray->ray_y);
}

static void	ft_init_dda_algorithm(t_cub *cub)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	if (ray->ray_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cub->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - cub->player.x)
			* ray->delta_dist_x;
	}
	if (ray->ray_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cub->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - cub->player.y)
			* ray->delta_dist_y;
	}
}

void	ft_apply_dda_algorithm(t_cub *cub)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	ray->wall_hit = false;
	while (!ray->wall_hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side_hit = false;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side_hit = true;
		}
		if (cub->map.grid[ray->map_x][ray->map_y] == '1')
			ray->wall_hit = true;
	}
	if (!ray->side_hit)
		ray->wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

static void	ft_calc_line_height(t_cub *cub)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	ray->line_height = (int)(HEIGHT / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

void	ft_raycast(t_cub *cub)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		ft_init_ray_directions(cub, x);
		ft_init_dda_algorithm(cub);
		ft_apply_dda_algorithm(cub);
		ft_calc_line_height(cub);
		ft_textures(cub, x);
	}
}
