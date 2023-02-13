/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:13:25 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/13 19:25:14 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	find_player(t_map *map)
{
	int	a;
	int	b;

	a = -1;
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

int	find_cmp(char *str1, char c)
{
	int	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] == c)
			return (1);
		i++;
	}
	return (0);
}