/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:43:38 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/21 17:16:18 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define RED 0x00FF0000
# define BLUE 0x0000FF
# define GREEN 0x7CFC00
# define WHITE 0xFFFFFF
# define GREY 0x808080
# define PURPLE 0x663399

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define ECHAP		53
# define UP			13
# define DOWN		1
# define LEFT		0
# define RIGHT		2
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define ENTER		76
# define RETURN		36
# define WIDTH	1280
# define HEIGHT 720
# define PI 3.14

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	rgb;
}	t_color;

typedef struct s_texture
{
	char	*nord;
	char	*sud;
	char	*est;
	char	*ouest;
	t_color	color_f;
	t_color	color_c;
	int		rx;
	int		ry;
	int		wdth;
	int		hght;
	void	*ptr;
	int		*addr;
	int		*dst;
	int		len;
	int		bpp;
	int		endian;
	int		texdir;
	double	wallx;
	int		texx;
	int		texy;
	double	step;
	double	texpos;
}	t_texture;

typedef struct s_ray
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planx;
	double	plany;
	double	camerax;
	double	raydirx;	
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	distwallp;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
}	t_ray;

typedef struct s_index
{
	int	i;
	int	c;
}	t_index;

typedef struct s_map
{
	int			fd;
	void		*mlx;
	void		*win;
	char		**map;
	char		**text;
	int			len;
	int			playx;
	int			playy;
	double		movespeed;
	double		rotspeed;
	t_index		index;
	t_color		color;
	t_texture	texture;
	t_ray		ray;
	void		*img;
	int			*addr;
	int			*dst;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_map;

//CLOSE.c
int			ft_close(t_map *map);
void		exit_error(char *str);

//ERROR.c
int			verif_wall(char **str);
int			verif_char(char **str);
int			ft_error(char **str);
int			error_cub(char *str);
void		error_text(t_map *map);

//INIT.c
void		init(t_map *map, char **argv);
void		init_ray(t_map *map);
void		init_dir(t_map *map);
void		ft_screen(t_map *map);
void		init_color(t_map *map);

//COLOR.c
void		reset_color(t_color *color);
int			calcul_rgb(t_color *color);
void		extract_color(t_map *map, t_color *color, char c);

//RAYCAST.c
void		reset_val(t_map *map);
void		op_vector(t_map *map);
void		calc_draw(t_map *map);

//ACTION_RAY.c
int			action_ray_game(int key, t_map *map);
void		player_ray_up(t_map *map);
void		player_ray_down(t_map *map);
void		player_rotate_left(t_map *map);
void		player_rotate_right(t_map *map);
void		player_ray_right(t_map *map);
void		player_ray_left(t_map *map);

//PARSE.c
void		init_map(t_map *map, char **argv);
void		extract_map(t_map *map, char **argv, int len);

//FREE.c
void		free_exit(t_map *map);

//PRINT.c
void		print_c(t_map *map);
void		print_f(t_map *map);
void		pixel_put3(t_map *map, int x, int color);
void		my_mlx_pixel(t_map *map, int x, int y, int color);

//PRINT_MAP.c
int			put_pix(t_map *map);
int			put_pix2(t_map *map);
void		pixel_square(t_map *map, int x, int y, int color);
void		pixel_square2(t_map *map, int x, int y, int color);

//TEXTURE.c
void		init_texture(t_map *map);
void		check_texture(t_map *map, char *path);
void		load_texture(t_map *map);
void		calc_texture(t_map *map);
void		put_wall(t_map *map, int x);

//UTILS_ALGO.c
void		pixel_wall(t_map *map, int x);
int			test_loop(t_map *map);
void		calc_dir_algo(t_map *map, int x);
void		check_ray(t_map *map);
void		loop_hit(t_map *map);

//UTILS.c
void		find_player(t_map *map);
int			find_cmp(char *str1, char c);
void		reset_ind(t_map *map);

#endif
