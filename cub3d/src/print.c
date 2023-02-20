/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:22:46 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/18 19:22:30 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	print_f(t_map *map)
{
	int	x;
	int	y;

	y = (map->texture.rY / 2);
	while (y < (map->texture.rY))
	{
		x = 0;
		while(x < map->texture.rX)
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
	while (y < (map->texture.rY / 2))
	{
		x = 0;
		while(x < map->texture.rX)
		{
			my_mlx_pixel(map, x, y, map->texture.color_c.rgb);
			x++;
		}
		y++;
	}
	return ;
}