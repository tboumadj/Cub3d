/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:22:46 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/20 23:34:30 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	print_f(t_map *map)
{
	int	x;
	int	y;

	y = (map->texture.ry / 2);
	while (y < (map->texture.ry))
	{
		x = 0;
		while (x < map->texture.rx)
		{
			my_mlx_pixel(map, x, y, map->texture.color_f.rgb);
			x++;
		}
		y++;
	}
	return ;
}

void	print_c(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < (map->texture.ry / 2))
	{
		x = 0;
		while (x < map->texture.rx)
		{
			my_mlx_pixel(map, x, y, map->texture.color_c.rgb);
			x++;
		}
		y++;
	}
	return ;
}

void	my_mlx_pixel(t_map *map, int x, int y, int color)
{
	char	*dst;

	dst = (char *)map->addr + (y * map->line_length + x
			* (map->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	pixel_put3(t_map *map, int x, int color)
{
	int	y;

	y = map->ray.drawstart;
	while (y <= map->ray.drawend)
	{
		my_mlx_pixel(map, x, y, color);
		y++;
	}
}
