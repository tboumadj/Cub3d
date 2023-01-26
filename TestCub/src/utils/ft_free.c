/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:27:14 by memam             #+#    #+#             */
/*   Updated: 2022/11/15 14:07:00 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	exit_error(char *msg, int code)
{
	ft_putstr_fd(msg, code);
	exit(code);
}

void	free_all(t_map *parma)
{
	int	i;

	i = -1;
	while (parma->map[++i])
	{
		free(parma->map[i]);
	}
	free(parma->map);
}

void	free_split(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
