/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:45:28 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/16 16:13:34 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int val_c(char c)
{
	if ((c == '1') || (c == '0') || (c == 'N') 
			|| (c == 'S') || (c == 'E') || (c == 'W'))
		return (0);
	return (1);
}
int	verif_wall(char **str)
{
	int	i;
	int	a;
	a = -1;
	while (str[++a + 1])
	{
		i = -1;
		while (str[a][++i])
			if (str[a][i] == '0')
				if ((val_c(str[a][i + 1])) || (val_c(str[a][i - 1]))
					|| (val_c(str[a + 1][i])) || (val_c(str[a - 1][i])
					|| (val_c(str[a + 1][i + 1])) || (val_c(str[a - 1][i + 1]))
					|| (val_c(str[a + 1][i - 1])) || (val_c(str[a - 1][i - 1])) 
					|| (i == 0) || (a == 0)))
					return (1);
	}
	i = -1;
	while (str[a][++i])
		if (str[a][i] == '0' || str[a][i] == 'N' || str[a][i] == 'S'
			|| str[a][i] == 'W' || str[a][i] == 'E')
			return (1);
	return (0);
}
int	verif_char(char **str)
{
	int	i;
	int	a;
	int c;
	a = -1;
	c = 0;
	while (str[++a])
	{
		i = 4;
		while (str[a][++i])
		{
			if ((str[a][i] != '0') && (str[a][i] != '1')
				&& (str[a][i] != '2') && (str[a][i] != 'N')
				&& (str[a][i] != 'S') && (str[a][i] != 'E')
				&& (str[a][i] != 'W') && (str[a][i] != ' ')
				&& (str[a][i] != '\n'))
				return (1);
			if (str[a][i] == 'N' || str[a][i] == 'S' || str[a][i] == 'E' 
					|| str[a][i] == 'W')
					c++;
		}
	}
	if (c != 1)
		return (1);
	return (0);
}

int	ft_error(char **str)
{
	if (verif_char(str))
		exit_error("Map have to be composed of 0, 1, 2, N, S, E, W");
	if (verif_wall(str))
		exit_error("Map have to be closed");
	return (0);
}

int	error_cub(char *str)
{
	if (ft_strncmp(str + ft_strlen(str) - 4, ".cub",4))
		return (1);
	return (0);
}

void	error_text(t_map *map)
{
	free_exit(map);
	exit_error("Texture cannot be open! \n");
}
