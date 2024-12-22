/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:11:08 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 03:38:37 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_free_map(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < cub->map.height)
		free(cub->map.grid[i]);
	free(cub->map.grid);
}

void	ft_free_textures(t_cub *cub)
{
	if (!cub->textures.mlx_textures)
		return ;
	if (cub->textures.mlx_textures[NORTH_DIRECTION].img)
		mlx_destroy_image(cub->mlx.mlx,
			cub->textures.mlx_textures[NORTH_DIRECTION].img);
	if (cub->textures.mlx_textures[SOUTH_DIRECTION].img)
		mlx_destroy_image(cub->mlx.mlx,
			cub->textures.mlx_textures[SOUTH_DIRECTION].img);
	if (cub->textures.mlx_textures[EAST_DIRECTION].img)
		mlx_destroy_image(cub->mlx.mlx,
			cub->textures.mlx_textures[EAST_DIRECTION].img);
	if (cub->textures.mlx_textures[WEST_DIRECTION].img)
		mlx_destroy_image(cub->mlx.mlx,
			cub->textures.mlx_textures[WEST_DIRECTION].img);
	free(cub->textures.mlx_textures);
}

int	ft_close(t_cub *cub)
{
	if (!cub)
		return (1);
	if (cub->mlx.win)
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	if (cub->mlx.img)
		mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
	ft_free_map(cub);
	ft_free_textures(cub);
	exit(EXIT_SUCCESS);
	return (0);
}
