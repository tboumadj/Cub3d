/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:14:52 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/21 17:37:27 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	player_ray_right(t_map *map)
{
	double	tempy;
	double	tempx;

	tempy = map->ray.posy;
	tempx = map->ray.posx;
	if (map->map[(int)(map->ray.posx)][(int)(map->ray.posy
			+ map->ray.diry + map->ray.plany)] == '0')
	{
		tempy += map->ray.plany * map->movespeed;
		tempx += map->ray.planx * map->movespeed;
		if (map->map[(int)tempx][(int)tempy] != '1')
		{
			map->ray.posy += map->ray.plany * map->movespeed;
			map->ray.posx += map->ray.planx * map->movespeed;
		}
	}
}

void	player_ray_left(t_map *map)
{
	double	tempy;
	double	tempx;

	tempy = map->ray.posy;
	tempx = map->ray.posx;
	if (map->map[(int)(map->ray.posx)][(int)(map->ray.posy
			+ map->ray.diry - map->ray.plany)] == '0')
	{
		tempy -= map->ray.plany * map->movespeed;
		tempx -= map->ray.planx * map->movespeed;
		if (map->map[(int)tempx][(int)tempy] != '1')
		{
			map->ray.posy -= map->ray.plany * map->movespeed;
			map->ray.posx -= map->ray.planx * map->movespeed;
		}
	}
}

void	player_ray_up(t_map *map)
{
	if (map->map[(int)(map->ray.posx + map->ray.dirx
			* map->movespeed)][(int)(map->ray.posy)] == '0')
		map->ray.posx += map->ray.dirx * map->movespeed;
	if (map->map[(int)(map->ray.posx)][(int)(map->ray.posy
			+ map->ray.diry * map->movespeed)] == '0')
		map->ray.posy += map->ray.diry * map->movespeed;
}

void	player_ray_down(t_map *map)
{
	if (map->map[(int)(map->ray.posx - map->ray.dirx
			* map->movespeed)][(int)(map->ray.posy)] == '0')
		map->ray.posx -= map->ray.dirx * map->movespeed;
	if (map->map[(int)(map->ray.posx)][(int)(map->ray.posy
			- map->ray.diry * map->movespeed)] == '0')
		map->ray.posy -= map->ray.diry * map->movespeed;
}
