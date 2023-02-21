/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcentupperx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:26:06 by tboumadj          #+#    #+#             */
/*   Updated: 2022/06/29 13:13:55 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strintupperx(unsigned int nb)
{
	int	str;

	str = 0;
	while (nb)
	{
		nb /= 16;
		str++;
	}
	return (str);
}

void	ft_putnbrupperx(unsigned int num)
{
	if (num >= 16)
	{
		ft_putnbrupperx(num / 16);
		ft_putnbrupperx(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'A');
	}
}

int	ft_pourcentupperx(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len += write(1, "0", 1);
	else
	{
		ft_putnbrupperx(num);
		len += ft_strintupperx(num);
	}
	return (len);
}
