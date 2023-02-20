/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:23:26 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/20 23:39:41 by tboumadj         ###   ########.fr       */
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

void	calc_dir_algo(t_map *map, int x)
{
	map->ray.camerax = 2 * x / (double)map->texture.rx - 1;
	map->ray.raydirx = map->ray.dirx + map->ray.planx * map->ray.camerax;
	map->ray.raydiry = map->ray.diry + map->ray.plany * map->ray.camerax;
	map->playx = (int)map->ray.posx;
	map->playy = (int)map->ray.posy;
	map->ray.deltadistx = fabs(1 / map->ray.raydirx);
	map->ray.deltadisty = fabs(1 / map->ray.raydiry);
	check_ray(map);
}

void	check_ray(t_map *map)
{
	if (map->ray.raydirx < 0)
	{
		map->ray.stepx = -1;
		map->ray.sidedistx = (map->ray.posx - map->playx)
			* map->ray.deltadistx;
	}
	else
	{
		map->ray.stepx = 1;
		map->ray.sidedistx = (map->playx + 1.0 - map->ray.posx)
			* map->ray.deltadistx;
	}
	if (map->ray.raydiry < 0)
	{
		map->ray.stepy = -1;
		map->ray.sidedisty = (map->ray.posy - map->playy)
			* map->ray.deltadisty;
	}
	else
	{
		map->ray.stepy = 1;
		map->ray.sidedisty = (map->playy + 1.0 - map->ray.posy)
			* map->ray.deltadisty;
	}
}

void	loop_hit(t_map *map)
{
	while (map->ray.hit == 0)
	{
		if (map->ray.sidedistx < map->ray.sidedisty)
		{
			map->ray.sidedistx += map->ray.deltadistx;
			map->playx += map->ray.stepx;
			map->ray.side = 0;
		}
		else
		{
			map->ray.sidedisty += map->ray.deltadisty;
			map->playy += map->ray.stepy;
			map->ray.side = 1;
		}
		if (map->map[map->playx][map->playy] == '1')
			map->ray.hit = 1;
	}
}
