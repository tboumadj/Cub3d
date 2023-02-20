/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:19:45 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/20 20:07:58 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		printf("Bad number of arguments !\n");
		exit(1);
	}
	init(&map, argv);
	test_loop(&map);
	mlx_hook(map.win, 2, 1L << 0, action_ray_game, &map);
	mlx_hook(map.win, 17, 1L << 17, ft_close, &map);
	mlx_loop(map.mlx);
	return (0);
}
