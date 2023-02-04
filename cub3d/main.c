/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:19:45 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/04 03:00:20 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main(int argc, char **argv)
{
	t_map map;
	
	if (argc != 2)
	{
		printf("Bad number of arguments !\n");
		exit(1);
	}
	init(&map, argv);
	//-------------------------------
	int i = 0;
	while (map.map[i])
		printf("map= %s", map.map[i++]);
	printf("\n");
	printf("\n");
	printf("posx = %d ", map.playX);
	printf("posy = %d\n", map.playY);
	printf("\n");
	i = 0;
	while (i < 7)
		printf("%s", map.text[i++]);
	printf("\n");
	//-----------------------------------
	//mlx_loop_hook(map.mlx, &test_loop, &map);
	//mlx_hook(map.win, 2, 1L << 0, action_ray_game, &map);
	//mlx_hook(map.win, 17, 1L << 17, ft_close, &map);
	//mlx_loop(map.mlx);
	free_exit(&map);
	return 0;
}