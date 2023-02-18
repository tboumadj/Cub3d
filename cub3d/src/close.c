/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:00:05 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/14 15:38:18 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_close(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	if(map->img)
		mlx_destroy_image(map->mlx, map->img);
	free_exit(map);
	exit(EXIT_SUCCESS);
	return (0);
}

void	close_action(t_map *map, int x, int y)
{
	(void) x;
	(void) y;
	put_pix(map);
}

void	exit_error(char *str)
{
	printf ("Error\n%s", str);
	exit (1);
}