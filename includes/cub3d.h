/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmheidat <mmheidat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:11:08 by mmheidat          #+#    #+#             */
/*   Updated: 2024/12/22 22:08:33 by mmheidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/libft.h"
# include "../libraries/get_next_line.h"
# include "../libraries/ft_printf.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>

# define RED 			"\033[0;31m"
# define PURPLE 		"\033[38;5;141m"
# define GREY 			"\033[38;5;240m"
# define GREEN 			"\033[38;5;46m"
# define RESET 			"\033[0m"
# define BOLD 			"\033[1m"

# define WIDTH		1280
# define HEIGHT		800

# define TEX_WIDTH		64
# define TEX_HEIGHT		64

# define NORTH_DIRECTION		0
# define SOUTH_DIRECTION		1
# define WEST_DIRECTION		2
# define EAST_DIRECTION		3

# define IDENTIFIER_LEN 3
# define INVALID_DIRECTION -1

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define LEFT 123
# define RIGHT 124

# define MOVE_SPEED		0.07
# define ROT_SPEED		0.05

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}				t_keys;

typedef struct s_player
{
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			old_dir_x;
	double			old_plane_x;
}				t_player;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	char			*addr;
	void			*img;
	int				bpp;
	int				line_len;
	int				endian;
}			t_mlx;

typedef struct s_map
{
	int				width;
	int				height;
	int				player_x;
	int				player_y;
	char			player_dir;
	char			**grid;
}				t_map;

typedef struct s_textures
{
	t_mlx	*mlx_textures;
	int		floor;
	int		ceiling;
}			t_textures;

typedef struct s_raycast
{
	bool	wall_hit;
	bool	side_hit;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		tex_x;
	int		tex_y;
	double	tex_step;
	double	tex_pos;
	double	tex_wall_x;
	double	ray_x;
	double	ray_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_dist;
}			t_raycast;

typedef struct s_cub
{
	t_mlx			mlx;
	t_player		player;
	t_map			map;
	t_textures		textures;
	t_raycast		raycast;
	t_keys			keys;
	char			*filepath;
}				t_cub;

/* ft_initializer.c */
t_cub		*ft_cub3d_init(char *filepath);

/* ft_raycaster.c */
void		ft_raycast(t_cub *cub);

/* ft_drawerc.c */
void		ft_textures(t_cub *cub, int x);

/* ft_args_checker.c */
char		*ft_get_file(char *filename);
void		check_arguments(int argc, char **argv);

/* ft_key_handler.c */
int			key_press(int keycode, t_cub *cub);

/* ft_mlx_utils.c */
int			ft_image_render(t_cub *cub);
int			ft_grab_pixel_rgb(t_mlx *mlx, int x, int y);
void		my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int			create_color(int t, int r, int g, int b);

/* ft_other_utils.c */
double		absolute_value(double x);
void		ft_error(char *message);
bool		is_valid_rgb(int r, int g, int b);
char		**ft_strsjoin(char **strs, char *str);
int			get_direction_from_identifier(char *identifier);

/* ft_parser.c */
t_map		parse_map_from_file(char *path);

/* ft_tx_parser.c */
t_textures	parse_textures_from_file(t_cub *cub, char *path);

/* ft_parser_utils.c */
bool		validate_map_structure(t_map map);
bool		is_map_line_valid(char *line);
void		locate_player_in_map(t_map *map);

/* ft_scan.c */
int			*parse_rgb_from_line(char *identifier, char *line);
int			ft_strslen(char **strs);

/* ft_floodfill_utils.c */
void		fl_find_player(t_map map, int *sr, int *sc);
bool		has_visited_boundary(bool **visited, t_map map);
void		free_visited_matrix(bool **visited, t_map map);

/* ft_floodfill.c */
bool		fl_can_exit(t_map map);

/* ft_free_utils.c */
int			ft_close(t_cub *cub);
int			process_movement(void *param);
int			key_release(int keycode, t_cub *cub);

// player movements

void		ft_move_up_down(int keycode, t_cub *cub);
void		ft_move_left_right(int keycode, t_cub *cub);
void		ft_move_rotate(int keycode, t_cub *cub);

#endif