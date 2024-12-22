/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:11:08 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 03:38:43 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

double	absolute_value(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ft_error(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

bool	is_valid_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (false);
	if (g < 0 || g > 255)
		return (false);
	if (b < 0 || b > 255)
		return (false);
	return (true);
}

int	get_direction_from_identifier(char *identifier)
{
	if (ft_strncmp(identifier, "NO ", IDENTIFIER_LEN) == 0)
		return (NORTH_DIRECTION);
	if (ft_strncmp(identifier, "SO ", IDENTIFIER_LEN) == 0)
		return (SOUTH_DIRECTION);
	if (ft_strncmp(identifier, "WE ", IDENTIFIER_LEN) == 0)
		return (WEST_DIRECTION);
	if (ft_strncmp(identifier, "EA ", IDENTIFIER_LEN) == 0)
		return (EAST_DIRECTION);
	return (INVALID_DIRECTION);
}
