/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:23:26 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/20 19:49:48 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	test_loop(t_map *map)
{
	print_f(map);
	print_c(map);
	op_vector(map);
	put_pix(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	return (0);
}

void	pixel_wall(t_map *map, int x)
{

	load_texture(map);
	calc_texture(map);
	put_wall(map, x);
}

void    calc_dir_algo(t_map *map, int x)
{
    map->ray.cameraX = 2 * x / (double)map->texture.rX - 1;
	map->ray.raydirX = map->ray.dirX + map->ray.planX * map->ray.cameraX;
	map->ray.raydirY = map->ray.dirY + map->ray.planY * map->ray.cameraX;
	map->playX = (int)map->ray.posX;
	map->playY = (int)map->ray.posY;
	map->ray.deltadistX = fabs(1 / map->ray.raydirX);
	map->ray.deltadistY = fabs(1 / map->ray.raydirY);
	check_ray(map);
}

void	check_ray(t_map *map)
{
	if (map->ray.raydirX < 0)
	{
		map->ray.stepX = -1;
		map->ray.sidedistX = (map->ray.posX - map->playX)
			* map->ray.deltadistX;
	}
	else
	{
		map->ray.stepX = 1;
		map->ray.sidedistX = (map->playX + 1.0 - map->ray.posX)
			* map->ray.deltadistX;
	}
	if (map->ray.raydirY < 0)
	{
		map->ray.stepY = -1;
		map->ray.sidedistY = (map->ray.posY - map->playY)
			* map->ray.deltadistY;
	}
	else
	{
		map->ray.stepY = 1;
		map->ray.sidedistY = (map->playY + 1.0 - map->ray.posY)
			* map->ray.deltadistY;
	}
}

void	loop_hit(t_map *map)
{
	while (map->ray.hit == 0)
	{
		if (map->ray.sidedistX < map->ray.sidedistY)
			{
				map->ray.sidedistX += map->ray.deltadistX;
				map->playX += map->ray.stepX;
				map->ray.side = 0;
			}
		else
			{
				map->ray.sidedistY += map->ray.deltadistY;
				map->playY += map->ray.stepY;
				map->ray.side = 1;
			}
		if (map->map[map->playX][map->playY] == '1')
				map->ray.hit = 1;
	}
}