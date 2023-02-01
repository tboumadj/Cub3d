/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:33:18 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/01 15:50:14 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init_map(t_map *map, char **argv)
{
	int		i;
	//int		j;
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
	//printf("i = %d", i - 7);
	map->len = i - 7;
	extract_map(map, argv, map->len);
	//-----------PRINT
	//j = 0;
	//while (j < 8)
	//	printf("texture = %s\n", map->text[j++]);
	//---------------
	return ;
}

void	extract_map(t_map *map, char **argv, int len)
{
	int 	i;
	char	*tmp;

	map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		exit(EXIT_FAILURE);
	//printf("ok\n");
	i = 0;
	map->map = malloc(sizeof(char *) * len);
	if (!map->map)
		return ;
	while (i < len -1)
	{
		//printf("loop\n");
		tmp = get_next_line(map->fd);
		if (tmp == NULL)
			{
				free (tmp);
				break ;
			}
		if (tmp[0] == '1')
		{
			//printf("map\n");
			map->map[i] = tmp;
			while (i < len - 1)
			{
				map->map[++i] = get_next_line(map->fd);
				//printf("map[%d]", i);
			}
			i++;
		}
		else
		{
			//printf("free\n");
			free(tmp);
		}
	}
	//map->map[i] = NULL;
	//----------PRINT
	/*i = 0;
	printf("map:\n");
	while (map->map[i])
		printf("%s", map->map[i++]);
	printf("\n");*/
	return ;
}
