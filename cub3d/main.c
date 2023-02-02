/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:19:45 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/02 16:12:10 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main(int argc, char **argv)
{
	t_map map;
	(void) argv;
	if (argc != 2)
	{
		printf("Bad number of arguments !\n");
		exit(1);
	}
	init(&map, argv);
	//mlx_hook(map.win, 17, 1L << 17, ft_close, &map);
	//mlx_loop(map.mlx);
	int i = 0;
	while (map.map[i])
		printf("%s", map.map[i++]);
	printf("\n");
	free_exit(&map);
	return 0;
}