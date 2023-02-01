/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:43:23 by tboumadj          #+#    #+#             */
/*   Updated: 2023/01/17 17:43:26 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	**init_tab(int fd)
{
	int		a;
	char	**str;

	str = malloc(sizeof(char *) * (100));
	a = -1;
	while (1)
	{
		str[++a] = get_next_line(fd);
		if (str[a] == NULL)
			break ;
	}
	return (str);
}