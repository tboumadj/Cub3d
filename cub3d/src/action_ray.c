/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:14:52 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/04 03:02:12 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	action_ray_game(int key, t_map *map)
{
	if (key == UP)
		player_ray_up(map);
	if (key == DOWN)
		player_ray_down(map);
	if (key == LEFT)
		player_ray_left(map);
	if (key == RIGHT)
		player_ray_right(map);
	if (key == ECHAP)
		ft_close(map);
	return (0);
}

void	player_ray_up(t_map *map)
{
	/*
	if (!map->map[(int)(map->ray.posX + map->ray.dirX * map->moveSpeed)][(int)(map->ray.posY)])
	{
		map->ray.posX += map->ray.dirX * map->moveSpeed;
		printf("posX move = %f\n", map->ray.posX);
	}
	if (!map->map[(int)(map->ray.posX)][(int)(map->ray.posY + map->ray.dirY * map->moveSpeed)])
	{
		map->ray.posY += map->ray.dirY * map->moveSpeed;
		printf("posX move = %f\n", map->ray.posX);
	}
	//put_pix(map);
	*/
	if (map->map[(int)(map->ray.posX + map->ray.dirX)][(int)(map->ray.posY + map->ray.dirY)] == '0')
	{
		map->ray.posX += map->ray.dirX * map->moveSpeed;
		map->ray.posY += map->ray.dirY * map->moveSpeed;
		printf("posX move = %f\n", map->ray.posX);
		printf("posY move = %f\n", map->ray.posY);
		map->map[(int)map->ray.posX][(int)map->ray.posY] = 'N';
		map->map[(int)map->playX][(int)map->playY] = '0';
		//put_pix2(map);
	}
}

void	player_ray_down(t_map *map)
{
	/*
	if (!map->map[(int)(map->ray.posX - map->ray.dirX * map->moveSpeed)][(int)(map->ray.posY)])
	{
		map->ray.posX -= map->ray.dirX * map->moveSpeed;
		//map->playX = (int)map->ray.posX;
	}
	if (!map->map[(int)(map->ray.posX)][(int)(map->ray.posY - map->ray.dirY * map->moveSpeed)])
	{
		map->ray.posY -= map->ray.dirY * map->moveSpeed;
		//map->playY = (int)map->ray.posY;
	}
	//put_pix(map);
	*/
	if (map->map[(int)(map->ray.posX - map->ray.dirX)][(int)(map->ray.posY - map->ray.dirY)] == '0')
	{
		map->ray.posX -= map->ray.dirX * map->moveSpeed;
		map->ray.posY -= map->ray.dirY * map->moveSpeed;
		printf("posX move = %f\n", map->ray.posX);
		printf("posY move = %f\n", map->ray.posY);
		map->map[(int)map->ray.posX][(int)map->ray.posY] = 'S';
		map->map[(int)map->playX][(int)map->playY] = '0';
		//put_pix2(map);
	}
}

void	player_ray_left(t_map *map)
{
	double oldDirX = map->ray.dirX;
	map->ray.dirX = map->ray.dirX * cos(-map->rotSpeed) - map->ray.dirY * sin(-map->rotSpeed);
	map->ray.dirY = oldDirX * sin(-map->rotSpeed) + map->ray.dirY * cos(-map->rotSpeed);
	double oldPlanX = map->ray.planX;
	map->ray.planX = map->ray.planX * cos(-map->rotSpeed) - map->ray.planY * sin(-map->rotSpeed);
	map->ray.planY = oldPlanX * sin(-map->rotSpeed) + map->ray.planY * cos(-map->rotSpeed);
}

void	player_ray_right(t_map *map)
{
	double oldDirX = map->ray.dirX;
	map->ray.dirX = map->ray.dirX * cos(map->rotSpeed) - map->ray.dirY * sin(map->rotSpeed);
	map->ray.dirY = oldDirX * sin(map->rotSpeed) + map->ray.dirY * cos(map->rotSpeed);
	double oldPlanX = map->ray.planX;
	map->ray.planX = map->ray.planX * cos(map->rotSpeed) - map->ray.planY * sin(map->rotSpeed);
	map->ray.planY = oldPlanX * sin(map->rotSpeed) + map->ray.planY * cos(map->rotSpeed);
}