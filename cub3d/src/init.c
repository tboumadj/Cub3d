/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:43:07 by tboumadj          #+#    #+#             */
/*   Updated: 2023/01/26 20:27:13 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	stock_text(t_map *map, char *path, char *str)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		if (!strncmp(map->map[i], str, 3))
			path = map->map[i] += 3;
		i++;
	}
	if (path == NULL)
		return (1);
	printf("%s= %s\n", str, path);
	return (0);
}

void	init(t_map *map, char **av)
{
	if (error_cub(av[1]))
		exit_error("Only .cub accepted");
	map->fd = open(av[1], O_RDONLY);
	map->map = init_tab(map->fd);
	map->playX = 0;
	map->playY = 0;
	init_ray(map);
	ft_error(map->map);
	if (stock_text(map, map->texture.nord, "NO ")
		|| stock_text(map, map->texture.sud, "SO ")
		|| stock_text(map, map->texture.ouest, "WE ")
		|| stock_text(map, map->texture.est, "EA "))
		exit_error("Fail textures load");
}

void	init_ray(t_map *map)
{
	map->moveSpeed = 0.2;
	map->rotSpeed = 0.2;
	//------------------
	map->ray.dirX = -1;
	map->ray.dirY = 0;
	map->ray.planX = 0;
	map->ray.planY = 0.66;
	map->ray.posX = (double)map->playX;
	map->ray.posY = (double)map->playY;
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
