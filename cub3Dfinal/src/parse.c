/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:33:18 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/20 22:54:58 by tboumadj         ###   ########.fr       */
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
	while (++i < 7)
		map->text[i] = get_next_line(map->fd);
	map->text[i] = NULL;
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
	char	*tmp;

	map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		exit(EXIT_FAILURE);
	map->map = malloc(sizeof(char *) * len);
	while (map->index.i < len -1)
	{
		tmp = get_next_line(map->fd);
		map->index.c++;
		if (tmp == NULL)
		{
			free (tmp);
			break ;
		}
		if (map->index.c > 7 && find_cmp(tmp, '1') == 1)
		{
			map->map[map->index.i] = tmp;
			while (map->index.i < len - 1)
				map->map[++map->index.i] = get_next_line(map->fd);
			map->index.i++;
		}
		else
			free(tmp);
	}
}
