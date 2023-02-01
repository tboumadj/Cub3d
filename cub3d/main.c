/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:19:45 by tboumadj@student  #+#    #+#             */
/*   Updated: 2023/02/01 00:22:44 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main(int argc, char **argv)
{
	t_map map;

	if (argc != 2)
	{
		printf("Bad number of arguments !\n");
		exit(1);
	}
	init(&map, argv);
}