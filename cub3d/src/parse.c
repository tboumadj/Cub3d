/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:33:18 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/01 13:09:50 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init_map(t_map *map)
{
	int	i;
	char **tmp;

	i = -1;
	map->text = malloc(sizeof(char *) * 8);
	while (++i < 8)
		map->text[i] = get_next_line(map->fd);
	map->text[i] = NULL;
	i = 0;
	tmp = malloc(sizeof(char *) * 100);
	while (1)
	{
		tmp[i] = get_next_line(map->fd);
		if (tmp[i][0] == '1')
			break;
		i++;
	}
	i = -1;
	map->map = malloc(sizeof(char *) * 100);
	while (1)
	{
		map->map[++i] = get_next_line(map->fd);
		if (map->map[i] == NULL)
			break;
	}
	free_tab(tmp);
	//-----------PRINT
	i = 0;
	while (i < 8)
		printf("texture = %s\n", map->text[i++]);
	i = -1;
	printf("map:\n");
	while (map->map[++i])
		printf("%s", map->map[i]);
	//---------------
}
