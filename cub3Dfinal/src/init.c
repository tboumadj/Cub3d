/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:30:02 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/20 20:10:40 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void    init(t_map *map, char **argv)
{
    if (error_cub(argv[1]))
        exit_error("Only .cub accepted!\n");
    map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		exit (EXIT_FAILURE);
	map->map = NULL;
	map->text = NULL;
	map->len = 0;
	map->texture.rX = width;
	map->texture.rY = height;
	map->color.r = -1;
	map->color.g = -1;
	map->color.b = -1;	
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
	map->win = mlx_new_window(map->mlx, map->texture.rX,
		map->texture.rY, "Cub3d");
	map->img = mlx_new_image(map->mlx, map->texture.rX,
		map->texture.rY);
	map->addr = (int*)mlx_get_data_addr(map->img, &map->bits_per_pixel,
		&map->line_length, &map->endian);
}


void	init_ray(t_map *map)
{
	map->moveSpeed = 0.15;
	map->rotSpeed = 0.09;
	init_dir(map);
	map->ray.posX = map->playX;
	map->ray.posY = map->playY;
	map->ray.cameraX = 0;
	map->ray.raydirX = 0;
	map->ray.raydirY = 0;
	map->ray.sidedistX = 0;
	map->ray.sidedistY = 0;
	map->ray.deltadistX = 0;
	map->ray.deltadistY = 0;
	map->ray.distwallP = 0;
	map->ray.stepX = 0;
	map->ray.stepY = 0;
	map->ray.hit = 0;
	map->ray.side = 0;
	map->ray.lineheight = 0;
	map->ray.drawstart = 0;
	map->ray.drawend = 0;
	map->map[map->playX][map->playY] = '0';
}

void	init_dir(t_map *map)
{
	map->ray.dirX = 0;
	map->ray.dirY = 0;
	map->ray.planX = 0;
	map->ray.planY = 0;
	if (map->map[map->playX][map->playY] == 'N')
		{
			map->ray.dirX = -1;
			map->ray.planY = 0.66;
		}
	if (map->map[map->playX][map->playY] == 'S')
	{
		map->ray.dirX = 1;
		map->ray.planY= -0.66;
	}
	if (map->map[map->playX][map->playY] == 'E')
	{
		map->ray.dirY = 1;
		map->ray.planX = 0.66;
	}
	if (map->map[map->playX][map->playY] == 'W')
	{
		map->ray.dirY = -1;
		map->ray.planX = -0.66;
	}
}
