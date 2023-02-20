/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:00:05 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/21 00:05:07 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_close(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	if (map->img)
		mlx_destroy_image(map->mlx, map->img);
	if (map->texture.nord)
		free(map->texture.nord);
	if (map->texture.sud)
		free(map->texture.sud);
	if (map->texture.ouest)
		free(map->texture.ouest);
	if (map->texture.est)
		free(map->texture.est);
	free_exit(map);
	exit(EXIT_SUCCESS);
	return (0);
}

void	exit_error(char *str)
{
	printf ("Error\n%s", str);
	exit (1);
}
