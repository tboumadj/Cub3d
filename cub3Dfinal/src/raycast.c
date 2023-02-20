/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:29:08 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/20 20:12:37 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	reset_val(t_map *map)
{
	map->ray.cameraX = 0;
	//map->ray.raydirX = 0;
	//map->ray.raydirY = 0;
	map->ray.sidedistX = 0;
	map->ray.sidedistY = 0;
	map->ray.deltadistX = 0;
	map->ray.distwallP = 0;
	map->ray.stepX = 0;
	map->ray.stepY = 0;
	map->ray.hit = 0;
	map->ray.side = 0;
	map->ray.lineheight = 0;
	map->ray.drawstart = 0;
	map->ray.drawend = 0;
}

void    op_vector(t_map *map)
{
	int	x;
	
	x = 0;
	while (x < map->texture.rX)
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
		//map->ray.distwallP = fabs((map->playX - map->ray.posX + (1 - map->ray.stepX) / 2) / map->ray.raydirX);
		map->ray.distwallP = (map->playX - map->ray.posX
			+ (1 - map->ray.stepX) / 2) / map->ray.raydirX;
	else
		//map->ray.distwallP = fabs((map->playY - map->ray.posY + (1 - map->ray.stepY) / 2) / map->ray.raydirY);
		map->ray.distwallP = (map->playY - map->ray.posY
			+ (1 - map->ray.stepY) / 2) / map->ray.raydirY;
	if(!map->ray.distwallP)
		map->ray.distwallP = 1;
	map->ray.lineheight = (int)(map->texture.rY / map->ray.distwallP);
	map->ray.drawstart = -map->ray.lineheight / 2 + map->texture.rY / 2;
	if (map->ray.drawstart < 0)
		map->ray.drawstart = 0;
	map->ray.drawend = map->ray.lineheight / 2 + map->texture.rY / 2;
	if ( map->ray.drawend >= map->texture.rY)
		map->ray.drawend = map->texture.rY - 1;
}