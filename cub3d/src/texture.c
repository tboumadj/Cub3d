/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:48:58 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/15 19:01:29 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init_texture(t_map *map)
{
	int i;

    i = -1;
    while (++i < 4)
    {
        if(ft_strncmp(map->text[i], "NO", 2) == 0)
            {
                map->texture.nord = ft_strdup(&map->text[i][3]);//Malloc!
                printf("nord = %s\n", map->texture.nord);
                if (open(map->texture.nord, O_RDONLY) == -1)
                    error_text(map);
            }
        if(ft_strncmp(map->text[i], "SO", 2) == 0)
            {
                map->texture.sud = ft_strdup(&map->text[i][3]);//Malloc!
                printf("sud = %s\n", map->texture.sud);
                if (open(map->texture.sud, O_RDONLY) == -1)
                    error_text(map);
            }
        if(ft_strncmp(map->text[i], "WE", 2) == 0)
            {
                map->texture.ouest = ft_strdup(&map->text[i][3]);//Malloc!
                printf("ouest = %s\n", map->texture.ouest);
                if (open(map->texture.ouest, O_RDONLY) == -1)
                    error_text(map);
            }
        if(ft_strncmp(map->text[i], "EA", 2) == 0)
            {
                map->texture.est = ft_strdup(&map->text[i][3]);//Malloc!
                printf("est = %s\n", map->texture.est);
                if (open(map->texture.est, O_RDONLY) == -1)
                    error_text(map);
            }
    }
}