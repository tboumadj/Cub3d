/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:30:02 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/20 23:22:43 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init(t_map *map, char **argv)
{
	if (error_cub(argv[1]))
		exit_error("Only .cub accepted!\n");
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		exit (EXIT_FAILURE);
	map->map = NULL;
	map->text = NULL;
	map->len = 0;
	map->texture.rx = WIDTH;
	map->texture.ry = HEIGHT;
	map->color.r = -1;
	map->color.g = -1;
	map->color.b = -1;
	map->index.i = 0;
	map->index.c = -1;
	init_map(map, argv);
	find_player(map);
	ft_error(map->map);
	init_color(map);
	init_texture(map);
	ft_screen(map);
	init_ray(map);
	return ;
}

void	init_color(t_map *map)
{
	map->texture.nord = NULL;
	map->texture.sud = NULL;
	map->texture.ouest = NULL;
	map->texture.est = NULL;
	reset_color(&map->texture.color_c);
	reset_color(&map->texture.color_f);
	extract_color(map, &map->texture.color_f, 'F');
	extract_color(map, &map->texture.color_c, 'C');
	map->texture.color_c.rgb = calcul_rgb(&map->texture.color_c);
	map->texture.color_f.rgb = calcul_rgb(&map->texture.color_f);
}

void	ft_screen(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->texture.rx,
			map->texture.ry, "Cub3d");
	map->img = mlx_new_image(map->mlx, map->texture.rx,
			map->texture.ry);
	map->addr = (int *)mlx_get_data_addr(map->img, &map->bits_per_pixel,
			&map->line_length, &map->endian);
}

void	init_ray(t_map *map)
{
	map->movespeed = 0.15;
	map->rotspeed = 0.09;
	init_dir(map);
	map->ray.posx = map->playx;
	map->ray.posy = map->playy;
	map->ray.camerax = 0;
	map->ray.raydirx = 0;
	map->ray.raydiry = 0;
	map->ray.sidedistx = 0;
	map->ray.sidedisty = 0;
	map->ray.deltadistx = 0;
	map->ray.deltadisty = 0;
	map->ray.distwallp = 0;
	map->ray.stepx = 0;
	map->ray.stepy = 0;
	map->ray.hit = 0;
	map->ray.side = 0;
	map->ray.lineheight = 0;
	map->ray.drawstart = 0;
	map->ray.drawend = 0;
	map->map[map->playx][map->playy] = '0';
}

void	init_dir(t_map *map)
{
	map->ray.dirx = 0;
	map->ray.diry = 0;
	map->ray.planx = 0;
	map->ray.plany = 0;
	if (map->map[map->playx][map->playy] == 'N')
	{
		map->ray.dirx = -1;
		map->ray.plany = 0.66;
	}
	if (map->map[map->playx][map->playy] == 'S')
	{
		map->ray.dirx = 1;
		map->ray.plany = -0.66;
	}
	if (map->map[map->playx][map->playy] == 'E')
	{
		map->ray.diry = 1;
		map->ray.planx = 0.66;
	}
	if (map->map[map->playx][map->playy] == 'W')
	{
		map->ray.diry = -1;
		map->ray.planx = -0.66;
	}
}
