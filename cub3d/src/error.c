/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:45:28 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/10 16:41:21 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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
				if ((str[a][i + 1] == ' ') || (str[a][i - 1] == ' ')
					|| (str[a + 1][i] == ' ') || (str[a - 1][i] == ' ')
					|| (str[a][i + 1] == '\n') || (str[a][i - 1] == '\n')
					|| (str[a + 1][i] == '\n') || (str[a - 1][i] == '\n') 
					|| (i == 0) || (a == 0) 
					|| (str[a + 1][i + 1] == ' ') || (str[a + 1][i - 1] == ' ') 
					|| (str[a - 1][i + 1] == ' ') || (str[a - 1][i - 1] == ' '))
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

//-------------------------------------//

void	exit_error(char *str)
{
	printf ("Error\n%s\n", str);
	exit (1);
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
	char	*tmp;
	int		i;
	int		x;

	i = 0;
	x = 0;
	tmp = ".cub";
	while (str[i])
		i++;
	while (str[i] != '.' && i > 0)
		i--;
	if (str[i] == '.')
	{
		while (tmp[x] == str[i] && tmp[x])
		{
			x++;
			i++;
		}
		if (x == 4 && str[i] == '\0')
			return (0);
	}
	return (1);
}
