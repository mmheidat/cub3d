/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:11:08 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 22:02:10 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub		*cub;

	check_arguments(argc, argv);
	cub = ft_cub3d_init(argv[1]);
	ft_image_render(cub);
	mlx_hook(cub->mlx.win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->mlx.win, 3, 1L << 1, key_release, cub);
	mlx_hook(cub->mlx.win, 17, 1L << 17, ft_close, cub);
	mlx_loop_hook(cub->mlx.mlx, process_movement, cub);
	mlx_loop(cub->mlx.mlx);
	return (0);
}
