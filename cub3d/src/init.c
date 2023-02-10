/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:30:02 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/10 18:11:55 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void    init(t_map *map, char **argv)
{
    if (error_cub(argv[1]))
        exit_error("Only .cub accepted!\n");
    map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		exit (EXIT_FAILURE);
	map->map = NULL;
	map->text = NULL;
	map->len = 0;
	map->texture.rX = width;
	map->texture.rY = height;
	map->color.r = -1;
	map->color.g = -1;
	map->color.b = -1;
	printf("rX = %d ", map->texture.rX);
	printf("rY = %d\n", map->texture.rY);
    init_map(map, argv);
	find_player(map);
	ft_error(map->map);
//-----------------------------------
	ft_screen(map);
	init_ray(map);
	return ;
}

void	ft_screen(t_map *map)
{
    map->mlx = mlx_init();
	//----------TEST SCREEN SIZE-------
	/*
	mlx_get_screen_size(map->mlx, &map->texture.screenX, &map->texture.screenY);
	map->texture.rX = (map->texture.rX > map->texture.screenX) ? map->texture.screenX : map->texture.rX;
	map->texture.rY = (map->texture.rY > map->texture.screenY) ? map->texture.screenY : map->texture.rY;
	printf("rX2 = %d ", map->texture.rX);
	printf("rY2 = %d\n", map->texture.rY);*/
	//---------------------
	map->win = mlx_new_window(map->mlx, map->texture.rX, map->texture.rY, "Cub3d");
	map->img = mlx_new_image(map->mlx, map->texture.rX, map->texture.rY);
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel, &map->line_length, &map->endian);
	//mlx_new_image(map->mlx, width, height);
}


void	init_ray(t_map *map)
{
	map->moveSpeed = 0.15;
	map->rotSpeed = 0.09;
	//------------------
	map->ray.dirX = -1;
	map->ray.dirY = 0;
	map->ray.planX = 0;
	map->ray.planY = 0.66;
	map->ray.posX = map->playX;
	map->ray.posY = map->playY;
	//-------------------
	map->ray.cameraX = 0;
	map->ray.raydirX = 0;
	map->ray.raydirY = 0;
	map->ray.sidedistX = 0;
	map->ray.sidedistY = 0;
	map->ray.deltadistX = 0;
	map->ray.deltadistY = 0;
	map->ray.distwallP = 0;
	map->ray.stepX = 0;
	map->ray.stepY = 0;
	map->ray.hit = 0;
	map->ray.side = 0;
	//-------------------
	map->ray.lineheight = 0;
	map->ray.drawstart = 0;
	map->ray.drawend = 0;
}

//--------------TEST---------------//

int	stock_text(t_map *map, char *path, char *str)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		if (!strncmp(map->text[i], str, 3))
			path = map->text[i] += 3;
		i++;
	}
	if (path == NULL)
		return (1);
	return (0);
}