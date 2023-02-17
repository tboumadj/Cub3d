/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:48:58 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/17 23:06:21 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	check_texture(t_map *map, char *path)
{
	printf("path = %s\n", path);
	if (open(path, O_RDONLY) == -1)
		error_text(map);
}

void	init_texture(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (ft_strncmp(map->text[i], "NO", 2) == 0)
			map->texture.nord = ft_strdup(&map->text[i][3]);//Malloc!
		if (ft_strncmp(map->text[i], "SO", 2) == 0)
			map->texture.sud = ft_strdup(&map->text[i][3]);//Malloc!
		if (ft_strncmp(map->text[i], "WE", 2) == 0)
			map->texture.ouest = ft_strdup(&map->text[i][3]);//Malloc!
		if (ft_strncmp(map->text[i], "EA", 2) == 0)
			map->texture.est = ft_strdup(&map->text[i][3]);//Malloc!
	}
	check_texture(map, map->texture.nord);
	check_texture(map, map->texture.sud);
	check_texture(map, map->texture.ouest);
	check_texture(map, map->texture.est);
}

void	load_texture(t_map *map)
{
	if (map->ray.side == 0 && map->ray.stepX == -1)
		map->texture.ptr = mlx_xpm_file_to_image(map->mlx,
			map->texture.nord, &map->texture.wdth, &map->texture.hght);
	else if (map->ray.side == 0 && map->ray.stepX == 1)
		map->texture.ptr = mlx_xpm_file_to_image(map->mlx,
			map->texture.sud, &map->texture.wdth, & map->texture.hght);
	else if (map->ray.side == 1 && map->ray.stepY == -1)
		map->texture.ptr = mlx_xpm_file_to_image(map->mlx,
			map->texture.ouest, &map->texture.wdth, &map->texture.hght);
	else if (map->ray.side == 1 && map->ray.stepY == 1)
		map->texture.ptr = mlx_xpm_file_to_image(map->mlx,
			map->texture.est, &map->texture.wdth, &map->texture.hght);
	map->texture.addr = mlx_get_data_addr(map->texture.ptr,
		&map->texture.len, &map->texture.bpp, &map->texture.endian);

}

void	calc_texture(t_map *map)
{
	if (map->ray.side == 0)
		map->texture.wallx = map->ray.posY + map->ray.distwallP * map->ray.raydirY;
	else
		map->texture.wallx = map->ray.posX + map->ray.distwallP * map->ray.raydirX;
	map->texture.wallx = (int)(map->texture.wallx);
	map->texture.texx = (int)(map->texture.wallx * (double)(map->texture.wdth));
	if (map->ray.side == 0 && map->ray.raydirX > 0)
		map->texture.texx = map->texture.wdth - map->texture.texx - 1;
	if (map->ray.side == 1 && map->ray.raydirX < 0)
		map->texture.texx = map->texture.wdth - map->texture.texx - 1;
	map->texture.step = 1.0 * map->texture.hght / map->ray.lineheight;
	map->texture.texpos = (map->ray.drawstart - map->texture.rY / 2 + map->ray.lineheight / 2) * map->texture.step;
}

void	put_wall(t_map *map, int x)
{
	int	color;
	int	y;
	int *dst;

	y = map->ray.drawstart;
	//printf("y = %d\n", y);
	//printf("x = %d\n", x);
	dst = (int*)map->addr;
	while (y < map->ray.drawend)
	{
		map->texture.texy = (int)map->texture.texpos & (map->texture.hght -1);
		map->texture.texpos += map->texture.step;
		color = (int)map->texture.addr[map->texture.hght * map->texture.texy + map->texture.texx];
		if (map->ray.side == 1)
			color = (color >> 1) & 8355711;
		dst[y * (map->texture.rX) + x] = color;
		//map->addr[y * (map->texture.rX) + x] = color;//WARNING
		y++;
	}
}

