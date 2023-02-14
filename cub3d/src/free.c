/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:32:01 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/04 03:04:09 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	free_exit(t_map *map)
{
	int i;

	i = 0;
	if (map->map != NULL)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
		i = 0;
	}
	if (map->text != NULL)
	{
		while (i < 7)
		{
			free(map->text[i]);
			i++;
		}
		free(map->text);
	}
	return ;
}
