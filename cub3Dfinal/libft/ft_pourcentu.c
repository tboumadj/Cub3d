/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcentu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:34:41 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/06/29 13:14:05 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strintu(unsigned int nb)
{
	unsigned int	str;

	str = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		str++;
	}
	return (str);
}

int	ft_pourcentu(unsigned int nb)
{
	int				len;
	unsigned int	n;

	n = nb;
	len = ft_strintu(n);
	if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_pourcentu(nb / 10);
		ft_pourcentu(nb % 10);
	}
	return (len);
}
