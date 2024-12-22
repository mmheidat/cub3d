/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:11:08 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 03:38:13 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	*ft_get_file(char *filename)
{
	int		length;
	int		i;

	if (!filename)
		return (NULL);
	length = ft_strlen(filename);
	i = length - 1;
	while (i >= 0 && filename[i] != '.' \
		&& filename[i] != '/' && filename[i] != '\\')
		i--;
	if (i > 0 && filename[i] == '.' \
		&& filename[i - 1] != '/' && filename[i - 1] != '\\')
		return (filename + i);
	else
		return (filename + length);
}

void	check_arguments(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		ft_error("invalid file input");
	if (ft_strncmp(ft_get_file(argv[1]), ".cub", ft_strlen(argv[1])))
		ft_error("invalid file extension");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(strerror(errno));
	close(fd);
}
