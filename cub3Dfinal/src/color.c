/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:10:19 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/20 22:40:29 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	calcul_rgb(t_color *color)
{
	return ((color->r << 16 | color->g << 8 | color->b));
}

void	extract_color(t_map *map, t_color *color, char c)
{
	int	i;
	int	j;

	i = 4;
	j = 1;
	while (map->text[i])
	{
		if (find_cmp(map->text[i], c) == 1)
		{
			color->r = ft_atoi(&map->text[i][j]);
			while (map->text[i][j] != ',')
				j++;
			color->g = ft_atoi(&map->text[i][++j]);
			while (map->text[i][j] != ',')
				j++;
			color->b = ft_atoi(&map->text[i][++j]);
			return ;
		}
		i++;
	}
	return ;
}

void	reset_color(t_color *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
}
