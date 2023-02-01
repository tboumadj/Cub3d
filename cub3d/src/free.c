/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:32:01 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/01 13:11:05 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;;
	while (tab[i])
	{
		free(tab[i++]);
	}
	free(tab);
	return;
}