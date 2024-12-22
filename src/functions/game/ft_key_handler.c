/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:11:08 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 16:40:22 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->keys.w = false;
	else if (keycode == A)
		cub->keys.a = false;
	else if (keycode == S)
		cub->keys.s = false;
	else if (keycode == D)
		cub->keys.d = false;
	else if (keycode == LEFT)
		cub->keys.left = false;
	else if (keycode == RIGHT)
		cub->keys.right = false;
	return (0);
}

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		ft_close(cub);
	else if (keycode == W)
		cub->keys.w = true;
	else if (keycode == A)
		cub->keys.a = true;
	else if (keycode == S)
		cub->keys.s = true;
	else if (keycode == D)
		cub->keys.d = true;
	else if (keycode == LEFT)
		cub->keys.left = true;
	else if (keycode == RIGHT)
		cub->keys.right = true;
	return (0);
}

int	process_movement(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (cub->keys.w)
		ft_move_up_down(W, cub);
	if (cub->keys.s)
		ft_move_up_down(S, cub);
	if (cub->keys.a)
		ft_move_left_right(A, cub);
	if (cub->keys.d)
		ft_move_left_right(D, cub);
	if (cub->keys.left)
		ft_move_rotate(LEFT, cub);
	if (cub->keys.right)
		ft_move_rotate(RIGHT, cub);
	ft_image_render(cub);
	return (0);
}

// int	key_press(int keycode, t_cub *cub)
// {
// 	if (keycode == ESC)
// 		ft_close(cub);
// 	ft_move_up_down(keycode, cub);
// 	ft_move_left_right(keycode, cub);
// 	ft_move_rotate(keycode, cub);
// 	ft_image_render(cub);
// 	return (0);
// }