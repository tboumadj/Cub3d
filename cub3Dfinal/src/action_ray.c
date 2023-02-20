/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:14:52 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/14 16:16:24 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	player_ray_right(t_map *map)
{
	if (map->map[(int)(map->ray.posX)][(int)(map->ray.posY
			+ map->ray.dirY + map->ray.planY)] == '0')
	{
		map->ray.posY += map->ray.planY * map->moveSpeed;
		map->ray.posX += map->ray.planX * map->moveSpeed;
	}
}

void	player_ray_left(t_map *map)
{
	if (map->map[(int)(map->ray.posX)][(int)(map->ray.posY
			+ map->ray.dirY - map->ray.planY)] == '0')
	{
		map->ray.posY -= map->ray.planY * map->moveSpeed;
		map->ray.posX -= map->ray.planX * map->moveSpeed;
	}
}

void	player_ray_up(t_map *map)
{
	if (map->map[(int)(map->ray.posX + map->ray.dirX
			* map->moveSpeed)][(int)(map->ray.posY)] == '0')
		map->ray.posX += map->ray.dirX * map->moveSpeed;
	if (map->map[(int)(map->ray.posX)][(int)(map->ray.posY
			+ map->ray.dirY * map->moveSpeed)] == '0')
		map->ray.posY += map->ray.dirY * map->moveSpeed;
}

void	player_ray_down(t_map *map)
{
	if (map->map[(int)(map->ray.posX - map->ray.dirX
			* map->moveSpeed)][(int)(map->ray.posY)] == '0')
		map->ray.posX -= map->ray.dirX * map->moveSpeed;
	if (map->map[(int)(map->ray.posX)][(int)(map->ray.posY
			- map->ray.dirY * map->moveSpeed)] == '0')
		map->ray.posY -= map->ray.dirY * map->moveSpeed;
}
