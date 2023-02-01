/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:43:43 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/01 00:23:41 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char *av[])
{
	t_map map;

	if (ac != 2)
	{
		printf("Bad number of arguments !\n");
		exit(1);
	}
	init(&map, av);
	//---------TEMP-----------//
	int	i = 8;
	while (map.map[i])
		printf("%s", map.map[i++]);
	//--------------------------//
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, width, height, "window");
	mlx_new_image(map.mlx, width, height);
	put_pix(&map);
	printf("playX = %d\n", map.playX);
	printf("playY = %d\n", map.playY);
	printf("posX = %d\n", (int)map.ray.posX);
	printf("posY = %d\n", (int)map.ray.posY);
	//mlx_hook(map.win, 2, 1L << 0, action_game, &map);
	//--------TEST-----------//
	mlx_loop_hook(map.mlx, &test_loop, &map);
	mlx_hook(map.win, 2, 1L << 0, action_ray_game, &map);
	//mlx_loop_hook(map.mlx, &put_pix, &map);
	//-----------------------//
	mlx_hook(map.win, 17, 1L << 17, ft_close, &map);
	mlx_loop(map.mlx);
}