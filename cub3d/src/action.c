/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:00:27 by tboumadj          #+#    #+#             */
/*   Updated: 2023/01/25 16:41:56 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	action_game(int key, t_map *map)
{
	if (key == UP)
		player_up(map);
	if (key == DOWN)
		player_down(map);
	if (key == LEFT)
		player_left(map);
	if (key == RIGHT)
		player_right(map);
	if (key == ECHAP)
		ft_close(map);
	return (0);
}

void	player_up(t_map *map)
{
	char	**tmp;

	tmp = map->map;
	if (tmp[map->playX][map->playY] == 'N')
	{
		if (tmp[map->playX -1][map->playY] != '1')
		{
			tmp[map->playX][map->playY] = '0';
			tmp[map->playX -1][map->playY] = 'N';
		}
		close_action(map, map->playX -1, map->playY);
	}
}

void	player_down(t_map *map)
{
	char	**tmp;

	tmp = map->map;
	if (tmp[map->playX][map->playY] == 'N')
	{
		if (tmp[map->playX +1][map->playY] != '1')
		{
			tmp[map->playX][map->playY] = '0';
			tmp[map->playX +1][map->playY] = 'N';
		}
		close_action(map, map->playX +1, map->playY);
	}
}

void	player_left(t_map *map)
{
	char	**tmp;

	tmp = map->map;
	if (tmp[map->playX][map->playY] == 'N')
	{
		if (tmp[map->playX][map->playY -1] != '1')
		{
			tmp[map->playX][map->playY] = '0';
			tmp[map->playX][map->playY -1] = 'N';
		}
		close_action(map, map->playX, map->playY -1);
	}
}

void	player_right(t_map *map)
{
	char	**tmp;

	tmp = map->map;
	if (tmp[map->playX][map->playY] == 'N')
	{
		if (tmp[map->playX][map->playY +1] != '1')
		{
			tmp[map->playX][map->playY] = '0';
			tmp[map->playX][map->playY +1] = 'N';
		}
		close_action(map, map->playX, map->playY +1);
	}
}
