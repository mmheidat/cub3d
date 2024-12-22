/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tx_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:11:08 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 03:38:26 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	parse_color(t_textures *texture, char *line)
{
	int	*rgb;

	if (line[0] == 'C')
	{
		if (texture->ceiling != -1)
			ft_error("ceiling color already set");
		rgb = parse_rgb_from_line("C", line);
		if (!is_valid_rgb(rgb[0], rgb[1], rgb[2]))
			ft_error("invalid rgb color");
		texture->ceiling = create_color(0, rgb[0], rgb[1], rgb[2]);
		free(rgb);
	}
	if (line[0] == 'F')
	{
		if (texture->floor != -1)
			ft_error("floor color already set");
		rgb = parse_rgb_from_line("F", line);
		if (!is_valid_rgb(rgb[0], rgb[1], rgb[2]))
			ft_error("invalid rgb color");
		texture->floor = create_color(0, rgb[0], rgb[1], rgb[2]);
		free(rgb);
	}
}

static void	parse_texture(t_cub *cub, t_textures texture, char *line, int dir)
{
	void	*image;
	int		height;
	int		width;

	height = TEX_HEIGHT;
	width = TEX_WIDTH;
	if (dir == -1)
		ft_error("invalid texture identifier");
	if (texture.mlx_textures[dir].img != NULL)
		ft_error("texture already set");
	line += 2;
	line = ft_strtrim(line, " \t\n");
	if (ft_strncmp(ft_get_file(line), ".xpm", ft_strlen(line)))
		ft_error("invalid texture extension");
	image = mlx_xpm_file_to_image(cub->mlx.mlx, line, &width, &height);
	free(line);
	if (!image)
		ft_error("texture not found");
	texture.mlx_textures[dir].img = image;
	texture.mlx_textures[dir].addr = mlx_get_data_addr(image, \
			&texture.mlx_textures[dir].bpp, \
			&texture.mlx_textures[dir].line_len, \
			&texture.mlx_textures[dir].endian);
	if (!texture.mlx_textures[dir].addr)
		ft_error("mlx_get_data_addr failed");
}

static void	ft_tx_init(t_textures *textures)
{
	textures->mlx_textures = malloc(sizeof(t_mlx) * 5);
	if (!textures->mlx_textures)
		ft_error("malloc error");
	textures->ceiling = -1;
	textures->floor = -1;
	textures->mlx_textures[NORTH_DIRECTION].img = NULL;
	textures->mlx_textures[SOUTH_DIRECTION].img = NULL;
	textures->mlx_textures[WEST_DIRECTION].img = NULL;
	textures->mlx_textures[EAST_DIRECTION].img = NULL;
}

static void	ft_check_textures(t_textures textures)
{
	if (textures.ceiling == -1 || textures.floor == -1)
		ft_error("missing color");
	if (textures.mlx_textures[NORTH_DIRECTION].img == NULL)
		ft_error("missing north texture");
	if (textures.mlx_textures[SOUTH_DIRECTION].img == NULL)
		ft_error("missing south texture");
	if (textures.mlx_textures[WEST_DIRECTION].img == NULL)
		ft_error("missing west texture");
	if (textures.mlx_textures[EAST_DIRECTION].img == NULL)
		ft_error("missing east texture");
}

t_textures	parse_textures_from_file(t_cub *cub, char *path)
{
	int			fd;
	char		*line;
	t_textures	textures;

	ft_tx_init(&textures);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("file not found");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = ft_free_to_trim(line, " \t");
		if (line[0] == 'N' || line[0] == 'S' || line[0] == 'E'
			|| line[0] == 'W')
			parse_texture(cub, textures, line,
				get_direction_from_identifier(line));
		if (line[0] == 'C' || line[0] == 'F')
			parse_color(&textures, line);
		free(line);
	}
	close(fd);
	ft_check_textures(textures);
	return (textures);
}
