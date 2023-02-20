/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:43:32 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/18 21:08:14 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cube.h"

int	put_pix(t_map *map)
{
	int	a;
	int	b;
	int	y;
	int	x;

	a = -1;
	y = 0;
	while (map->map[++a])
	{
		b = -1;
		x = 10;
		while (map->map[a][++b])
		{
			if (map->map[a][b] == '1')
				pixel_square(map, x, y, PURPLE);
			else if ((int)map->ray.posY == b && (int)map->ray.posX == a)
					pixel_square(map, x, y, GREEN);
			else if (map->map[a][b] == '0')
				pixel_square2(map, x, y, PURPLE);
			x += 10;
		}
		y += 10;
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
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			my_mlx_pixel(map, x++, y, color);
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
	while (j < 5)
	{
		i = 0;
		if (j == 0)
		{
			while (i <= 5)
			{
				my_mlx_pixel(map, x++, y, color);
				i++;
			}
		}
		else
		{
			while (i < 5)
			{
				if (i == 0)
					my_mlx_pixel(map, x++, y, color);
				i++;
				x++;
			}
		}
		x = tmp;
		y++;
		j++;
	}
}