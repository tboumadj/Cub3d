/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:29:08 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/20 23:36:41 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	reset_val(t_map *map)
{
	map->ray.camerax = 0;
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
}

void	op_vector(t_map *map)
{
	int	x;

	x = 0;
	while (x < map->texture.rx)
	{
		reset_val(map);
		calc_dir_algo(map, x);
		loop_hit(map);
		calc_draw(map);
		pixel_wall(map, x);
		x++;
	}
}

void	calc_draw(t_map *map)
{
	if (map->ray.side == 0)
		map->ray.distwallp = (map->playx - map->ray.posx
				+ (1 - map->ray.stepx) / 2) / map->ray.raydirx;
	else
		map->ray.distwallp = (map->playy - map->ray.posy
				+ (1 - map->ray.stepy) / 2) / map->ray.raydiry;
	if (!map->ray.distwallp)
		map->ray.distwallp = 1;
	map->ray.lineheight = (int)(map->texture.ry / map->ray.distwallp);
	map->ray.drawstart = -map->ray.lineheight / 2 + map->texture.ry / 2;
	if (map->ray.drawstart < 0)
		map->ray.drawstart = 0;
	map->ray.drawend = map->ray.lineheight / 2 + map->texture.ry / 2;
	if (map->ray.drawend >= map->texture.ry)
		map->ray.drawend = map->texture.ry - 1;
}
