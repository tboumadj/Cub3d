/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:33:18 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/02 16:05:25 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init_map(t_map *map, char **argv)
{
	int		i;
	char	*tmp;
	
	i = -1;
	map->text = malloc(sizeof(char *) * 8);
	if (!map->text)
		return ;
	while (++i < 8)
		map->text[i] = get_next_line(map->fd);
	while (1)
	{
		tmp = get_next_line(map->fd);
		i++;
		if (tmp == NULL)
		{
			free(tmp);
			break ;
		}
		free(tmp);
	}
	map->len = i - 7;
	extract_map(map, argv, map->len);
	return ;
}

void	extract_map(t_map *map, char **argv, int len)
{
	int 	i;
	char	*tmp;

	map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		exit(EXIT_FAILURE);
	i = 0;
	map->map = malloc(sizeof(char *) * len);
	if (!map->map)
		return ;
	while (i < len -1)
	{
		tmp = get_next_line(map->fd);
		if (tmp == NULL)
			{
				free (tmp);
				break ;
			}
		if (tmp[0] == '1')
		{
			map->map[i] = tmp;
			while (i < len - 1)
				map->map[++i] = get_next_line(map->fd);
			i++;
		}
		else
			free(tmp);
	}
	return ;
}
