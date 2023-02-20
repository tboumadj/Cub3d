/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:33:18 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/20 20:11:23 by tboumadj@student ###   ########.fr       */
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
	int 	i;
	int		c;
	char	*tmp;

	map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		exit(EXIT_FAILURE);
	i = 0;
	c = 0;
	map->map = malloc(sizeof(char *) * len);
	if (!map->map)
		return ;
	while (i < len -1)
	{
		tmp = get_next_line(map->fd);
		c++;
		if (tmp == NULL)
			{
				free (tmp);
				break ;
			}
		if (c > 7 && find_cmp(tmp, '1') == 1)
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
