/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:59:38 by psydenst          #+#    #+#             */
/*   Updated: 2022/06/30 14:46:51 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_len_ptr(unsigned long nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

void	ft_put_ptr(unsigned long nbr, const char format)
{
	if (nbr >= 16)
	{
		ft_put_ptr(nbr / 16, format);
		ft_put_ptr(nbr % 16, format);
	}
	else
		if (nbr < 10)
			ft_putchar(nbr + '0');
	else
	{
		if (format == 'p')
			ft_putchar(nbr - 10 + 'a');
	}
}

int	ft_print_ptr(void *nbr, const char format)
{
	ft_putstr("0x");
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	else
		ft_put_ptr((unsigned long)nbr, format);
	return (ft_len_ptr((unsigned long)nbr) + 2);
}
