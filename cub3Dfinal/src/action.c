/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:13:12 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/20 22:38:28 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	action_ray_game(int key, t_map *map)
{
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
	test_loop(map);
	return (0);
}

void	player_rotate_right(t_map *map)
{
	double	olddirx;
	double	oldplanx;

	olddirx = map->ray.dirx;
	map->ray.dirx = map->ray.dirx * cos(-map->rotspeed)
		- map->ray.diry * sin(-map->rotspeed);
	map->ray.diry = olddirx * sin(-map->rotspeed)
		+ map->ray.diry * cos(-map->rotspeed);
	oldplanx = map->ray.planx;
	map->ray.planx = map->ray.planx * cos(-map->rotspeed)
		- map->ray.plany * sin(-map->rotspeed);
	map->ray.plany = oldplanx * sin(-map->rotspeed)
		+ map->ray.plany * cos(-map->rotspeed);
}

void	player_rotate_left(t_map *map)
{
	double	olddirx;
	double	oldplanx;

	olddirx = map->ray.dirx;
	map->ray.dirx = map->ray.dirx * cos(map->rotspeed)
		- map->ray.diry * sin(map->rotspeed);
	map->ray.diry = olddirx * sin(map->rotspeed)
		+ map->ray.diry * cos(map->rotspeed);
	oldplanx = map->ray.planx;
	map->ray.planx = map->ray.planx * cos(map->rotspeed)
		- map->ray.plany * sin(map->rotspeed);
	map->ray.plany = oldplanx * sin(map->rotspeed)
		+ map->ray.plany * cos(map->rotspeed);
}
