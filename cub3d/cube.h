/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:43:38 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/10 16:30:38 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

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
# define width	1280 //420
# define height 720 //380

typedef struct s_texture
{
	char	*nord;
	char 	*sud;
	char 	*est;
	char 	*ouest;
	int		screenX;
	int		screenY;
	int		rX;
	int		rY;
} t_texture;

typedef struct s_ray
{
	double	posX;	//-pos joueur sur map double (vertical X)
	double 	posY;	//-pos joueur sur map double (horizon Y)
	double	dirX;	//-direction du vecteur (-1N, 1S, 0)
	double	dirY;	//-direction du verccteur (-1W, 1E, 0)
	double	planX;	//-vecteur plan (0.66.E, -0.66W, 0)
	double	planY;	//-vecteur plan (0.66N, -0.66S, 0)

	double	cameraX;	//camera sur X (G.-1, C.0, D.1) | cameraX= 2 * x / (double)width -1
	double	raydirX;	//calcul direction X rayon | rdX= dirX + planX * cameraX	
	double	raydirY;	//calcul direction Y rayon | rdY= dirY + planY * cameraX
	
	double	sidedistX;	//distance rayon jusq. inter. vertical (x)
	double	sidedistY;	//distance rayon jusq. inter. horizon (y)
	double	deltadistX;	//distance entre chaq. inter. vertical (x)
	double	deltadistY;	//distance entre chaq. inter. horizon (y)
	double	distwallP;	//distance du joueur au mur

	int		stepX;	//-1 si saut carre neg. (X)/ 1 si (X) positif
	int		stepY;	//-1 si saut carre neg (Y)/	1 si (Y) positif
	int		hit;	//1 si mur hit/ else 0
	int		side;	//0 si cote hit = X / 1 si cote hit = Y

	//printwall
	int		lineheight;	//hauteur ligne to draw	| lineheight= (int)(height/distwallP)
	int		drawstart;	//start pos to draw	| drawstart= -lineheight / 2 + height / 2
	int		drawend;	//end pos to draw	| drawend=	lineheight / 2 + height / 2
} t_ray;

typedef struct s_map
{
	int 	fd;
	void	*mlx;
	void	*win;
	char 	**map;
	char	**text;
	int		len;
	int		playX;	//pos joueur sur map (vertical X)   (= posX)
	int		playY;	//pos joueur sur map (horizontal Y)	(= posY)
	double	moveSpeed; //-vitesse mouvement joueur
	double	rotSpeed; //-vitesse rotation joueur
	t_texture texture;
	t_ray	ray;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
} t_map;

//CLOSE.c
int			ft_close(t_map *map);
void		close_action(t_map *map, int x, int y);

//ERROR.c
int			verif_wall(char **str);
int			verif_char(char **str);
void 		exit_error(char *str);
int     	ft_error(char **str);
int			error_cub(char *str);

//INIT.c
int 		stock_text(t_map *map, char *path, char *str);
void		init(t_map *map, char **argv);
void		init_ray(t_map *map);
void		ft_screen(t_map *map);

//RAYCAST.c
void		pixel_put3(t_map *map, int x, int color);
int    		test_loop(t_map *map);
void    	op_vector(t_map *map);

//ACTION_RAY.c
int			action_ray_game(int key, t_map *map);
void		player_ray_up(t_map *map);
void		player_ray_down(t_map *map);
void		player_ray_left(t_map *map);
void		player_ray_right(t_map *map);

//PARSE.c
void		init_map(t_map *map, char **argv);
void		extract_map(t_map *map, char **argv, int len);

//FREE.c
void		free_exit(t_map *map);

//PRINT.c
void		print_c(t_map *map);
void		print_f(t_map *map);

//PRINT_MAP.c
int 		put_pix(t_map *map);
int			put_pix2(t_map *map);//USELESS
void		pixel_square(t_map *map, int x, int y, int color);
void		pixel_square2(t_map *map, int x, int y, int color);

//UTILS.c
void		find_player(t_map *map);
int			find_cmp(char *str1, char c);

//------------TEST-----------------//
void		pixel_player(t_map *map, int x, int y, int color);
void		reset_val(t_map *map);
void		my_mlx_pixel(t_map *map, int x, int y, int color);

#endif
