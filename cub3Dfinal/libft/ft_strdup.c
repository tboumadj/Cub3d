/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:01:37 by tboumadj          #+#    #+#             */
/*   Updated: 2023/02/15 19:00:25 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		a;
	int		b;

	b = 0;
	while (s[b])
		++b;
	dest = malloc(sizeof(*s) * b + 1);
	if (!dest)
		return (NULL);
	a = 0;
	while (s[a] != '\0' && s[a] != '\n')
	{
		dest[a] = s[a];
		++a;
	}
	dest[a] = '\0';
	return (dest);
}
