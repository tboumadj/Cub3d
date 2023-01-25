/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:43:43 by tboumadj          #+#    #+#             */
/*   Updated: 2023/01/25 17:15:18 by tboumadj         ###   ########.fr       */
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
	mlx_hook(map.win, 2, 1L << 0, action_game, &map);
	mlx_hook(map.win, 17, 1L << 17, ft_close, &map);
	mlx_loop(map.mlx);
}