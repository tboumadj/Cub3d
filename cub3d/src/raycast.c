/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:29:08 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/18 21:12:03 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	reset_val(t_map *map)
{
	map->ray.cameraX = 0;
	//map->ray.raydirX = 0;
	//map->ray.raydirY = 0;
	map->ray.sidedistX = 0;
	map->ray.sidedistY = 0;
	map->ray.deltadistX = 0;
	map->ray.distwallP = 0;
	map->ray.stepX = 0;
	map->ray.stepY = 0;
	map->ray.hit = 0;
	map->ray.side = 0;
	map->ray.lineheight = 0;
	map->ray.drawstart = 0;
	map->ray.drawend = 0;
}

void	my_mlx_pixel(t_map *map, int x, int y, int color)
{
	char	*dst;

	dst = (char*)map->addr + (y * map->line_length + x * (map->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	test_loop(t_map *map)
{
	print_f(map);
	print_c(map);
	op_vector(map);
	put_pix(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	return (0);
}

void	pixel_wall(t_map *map, int x)
{

	load_texture(map);
	calc_texture(map);
	put_wall(map, x);
}

void	pixel_put3(t_map *map, int x, int color)
{
	int y;


	y = map->ray.drawstart;
	while (y <= map->ray.drawend)
	{
		my_mlx_pixel(map, x, y, color);
		y++;
	}
	//mlx_clear_window(map->mlx, map->win);
	//mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
}

void    op_vector(t_map *map)
{
	int	x;
	int	color;
	
	x = 0;
	color = 0;
	while (x < map->texture.rX)
	{
		reset_val(map);
		map->ray.cameraX = 2 * x / (double)map->texture.rX - 1;
		map->ray.raydirX = map->ray.dirX + map->ray.planX * map->ray.cameraX;
		map->ray.raydirY = map->ray.dirY + map->ray.planY * map->ray.cameraX;

		map->playX = (int)map->ray.posX;
		map->playY = (int)map->ray.posY;
		//printf("playX = %d", map->playX);
		//printf("playY = %d", map->playY);

		map->ray.deltadistX = fabs(1 / map->ray.raydirX);
		map->ray.deltadistY = fabs(1 / map->ray.raydirY);
		//map->ray.deltadistX = sqrt(1 + pow(map->ray.raydirY, 2) / pow(map->ray.dirX, 2));
		//map->ray.deltadistY = sqrt(1 + pow(map->ray.raydirX, 2) / pow(map->ray.dirY, 2));

		if (map->ray.raydirX < 0)
		{
			map->ray.stepX = -1;
			map->ray.sidedistX = (map->ray.posX - map->playX) * map->ray.deltadistX;
		}
		else
		{
			map->ray.stepX = 1;
			map->ray.sidedistX = (map->playX + 1.0 - map->ray.posX) * map->ray.deltadistX;
		}
		//-----------------------------//
		if (map->ray.raydirY < 0)
		{
			map->ray.stepY = -1;
			map->ray.sidedistY = (map->ray.posY - map->playY) * map->ray.deltadistY;
		}
		else
		{
			map->ray.stepY = 1;
			map->ray.sidedistY = (map->playY + 1.0 - map->ray.posY) * map->ray.deltadistY;
		}
		//-------------------------//
		while ( map->ray.hit == 0)
		{
			if (map->ray.sidedistX < map->ray.sidedistY)
			{
				map->ray.sidedistX += map->ray.deltadistX;
				map->playX += map->ray.stepX;
				map->ray.side = 0;
			}
			else
			{
				map->ray.sidedistY += map->ray.deltadistY;
				map->playY += map->ray.stepY;
				map->ray.side = 1;
			}
			if (map->map[map->playX][map->playY] == '1')
				map->ray.hit = 1;
		}
		//--------------------------//
		if (map->ray.side == 0)
			//map->ray.distwallP = fabs((map->playX - map->ray.posX + (1 - map->ray.stepX) / 2) / map->ray.raydirX);
			map->ray.distwallP = (map->playX - map->ray.posX + (1 - map->ray.stepX) / 2) / map->ray.raydirX;
		else
			//map->ray.distwallP = fabs((map->playY - map->ray.posY + (1 - map->ray.stepY) / 2) / map->ray.raydirY);
			map->ray.distwallP = (map->playY - map->ray.posY + (1 - map->ray.stepY) / 2) / map->ray.raydirY;
		//-------TEST----------------//
		if(!map->ray.distwallP)
			map->ray.distwallP = 1;
		//---------DRAW-------------//
		map->ray.lineheight = (int)(map->texture.rY / map->ray.distwallP);
		map->ray.drawstart = -map->ray.lineheight / 2 + map->texture.rY / 2;
		if (map->ray.drawstart < 0)
			map->ray.drawstart = 0;
		map->ray.drawend = map->ray.lineheight / 2 + map->texture.rY / 2;
		if ( map->ray.drawend >= map->texture.rY)
			map->ray.drawend = map->texture.rY - 1;
			
		//--------COLOR--------//
		if (map->map[map->playX][map->playY] == '1')
			color = GREY;
		else 
			color = WHITE;

		if (map->ray.side == 1)
			color = color / 2;
		//print_c(map);
		//print_f(map);
		//pixel_put3(map, x, color);
		pixel_wall(map, x);
		
		x++;
		//mlx_clear_window(map->mlx, map->win);
	}
	//mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
}