/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:14:52 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/13 19:32:28 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	action_ray_game(int key, t_map *map)
{
	//print_c(map);
	//print_f(map);
	//mlx_clear_window(map->mlx, map->win);
	if (key == UP)
		player_ray_up(map);
	if (key == DOWN)
		player_ray_down(map);
	if (key == ROTATE_LEFT)
		player_rotate_left(map);
	if (key == ROTATE_RIGHT)
		player_rotate_right(map);
	if (key == LEFT)
		player_ray_left(map);
	if (key == RIGHT)
		player_ray_right(map);
	if (key == ECHAP)
		ft_close(map);
	test_loop(map);//TEST
	//op_vector(map);
	return (0);
}

void	player_ray_right(t_map *map)
{
	if (map->map[(int)(map->ray.posX)][(int)(map->ray.posY + map->ray.dirY + map->ray.planY)] == '0')
	{
		map->ray.posY += map->ray.planY * map->moveSpeed;
		map->ray.posX += map->ray.planX * map->moveSpeed;
	}
}

void	player_ray_left(t_map *map)
{
	if (map->map[(int)(map->ray.posX)][(int)(map->ray.posY + map->ray.dirY - map->ray.planY)] == '0')
	{
		map->ray.posY -= map->ray.planY * map->moveSpeed;
		map->ray.posX -= map->ray.planX * map->moveSpeed;
	}
}

void	player_ray_up(t_map *map)
{
	if (map->map[(int)(map->ray.posX + map->ray.dirX * map->moveSpeed)][(int)(map->ray.posY)] == '0')
		map->ray.posX += map->ray.dirX * map->moveSpeed;
	if (map->map[(int)(map->ray.posX)][(int)(map->ray.posY + map->ray.dirY * map->moveSpeed)] == '0')
		map->ray.posY += map->ray.dirY * map->moveSpeed;
}
void	player_ray_down(t_map *map)
{
	
	if (map->map[(int)(map->ray.posX - map->ray.dirX * map->moveSpeed)][(int)(map->ray.posY)] == '0')
		map->ray.posX -= map->ray.dirX * map->moveSpeed;
	if (map->map[(int)(map->ray.posX)][(int)(map->ray.posY - map->ray.dirY * map->moveSpeed)] == '0')
		map->ray.posY -= map->ray.dirY * map->moveSpeed;
}

void	player_rotate_right(t_map *map)
{
	double oldDirX = map->ray.dirX;
	map->ray.dirX = map->ray.dirX * cos(-map->rotSpeed) - map->ray.dirY * sin(-map->rotSpeed);
	map->ray.dirY = oldDirX * sin(-map->rotSpeed) + map->ray.dirY * cos(-map->rotSpeed);
	double oldPlanX = map->ray.planX;
	map->ray.planX = map->ray.planX * cos(-map->rotSpeed) - map->ray.planY * sin(-map->rotSpeed);
	map->ray.planY = oldPlanX * sin(-map->rotSpeed) + map->ray.planY * cos(-map->rotSpeed);
}

void	player_rotate_left(t_map *map)
{
	double oldDirX = map->ray.dirX;
	map->ray.dirX = map->ray.dirX * cos(map->rotSpeed) - map->ray.dirY * sin(map->rotSpeed);
	map->ray.dirY = oldDirX * sin(map->rotSpeed) + map->ray.dirY * cos(map->rotSpeed);
	double oldPlanX = map->ray.planX;
	map->ray.planX = map->ray.planX * cos(map->rotSpeed) - map->ray.planY * sin(map->rotSpeed);
	map->ray.planY = oldPlanX * sin(map->rotSpeed) + map->ray.planY * cos(map->rotSpeed);
}