/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:13:25 by tboumadj          #+#    #+#             */
/*   Updated: 2023/01/31 15:07:35 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	if_green(t_map *map)
{
	find_player(map);
	map->ray.posX = (double)map->playX;
	map->ray.posY = (double)map->playY;
	
	return ;
}

void	find_player(t_map *map)
{
	int	a;
	int	b;

	a = 7;
	while (map->map[++a])
	{
		b = -1;
		while (map->map[a][++b])
		{
			if (map->map[a][b] == 'N' || map->map[a][b] == 'W'
				|| map->map[a][b] == 'S' || map->map[a][b] == 'E')
			{
				map->playX = a;
				map->playY = b;
			}
		}
	}
}