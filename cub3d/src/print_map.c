/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:43:32 by tboumadj          #+#    #+#             */
/*   Updated: 2023/01/27 14:49:33 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	put_pix(t_map *map)
{
	int	a;
	int	b;
	int	y;
	int	x;

	a = 7;
	y = 10;
	mlx_clear_window(map->mlx, map->win);
	while (map->map[++a])
	{
		b = -1;
		x = 10;
		while (map->map[a][++b])
		{
			if (map->map[a][b] == '1')
				pixel_square(map, x, y, GREY);
			else if (map->map[a][b] == '0')
				pixel_square2(map, x, y, GREY);
			else if (map->map[a][b] == 'N' || map->map[a][b] == 'W'
				|| map->map[a][b] == 'S' || map->map[a][b] == 'E')
					pixel_square(map, x, y, GREEN);
			x += 9;
		}
		y += 9;
	}
	return (0);
}

int	put_pix2(t_map *map)
{
	int	a;
	int	b;
	int	y;
	int	x;

	a = 7;
	y = 10;
	while (map->map[++a])
	{
		b = -1;
		x = 10;
		while (map->map[a][++b])
		{
			if (map->map[a][b] == 'N' || map->map[a][b] == 'W'
				|| map->map[a][b] == 'S' || map->map[a][b] == 'E')
					pixel_square(map, x, y, GREEN);
			x += 9;
		}
		y += 9;
	}
	return (0);
}

void	pixel_square(t_map *map, int x, int y, int color)
{
	int	i;
	int	j;
	int	tmp;

	tmp = x;
	j = 0;
	if (color == GREEN)
		if_green(map);
	while (j < 7)
	{
		i = 0;
		while (i < 7)
		{
			mlx_pixel_put(map->mlx, map->win, x++, y, color);
			i++;
		}
		x = tmp;
		y++;
		j++;
	}
}

void	pixel_square2(t_map *map, int x, int y, int color)
{
	int	i;
	int	j;
	int	tmp;

	tmp = x;
	j = 0;
	while (j < 7)
	{
		i = 0;
		if (j == 0)
		{
			while (i <= 7)
			{
				mlx_pixel_put(map->mlx, map->win, x++, y, color);
				i++;
			}
		}
		else
		{
			while (i < 7)
			{
				if (i == 0)
					mlx_pixel_put(map->mlx, map->win, x++, y, color);
				i++;
				x++;
			}
		}
		x = tmp;
		y++;
		j++;
	}
}
