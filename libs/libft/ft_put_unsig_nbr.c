/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsig_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:28:59 by psydenst          #+#    #+#             */
/*   Updated: 2022/06/29 17:38:23 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_u_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_put_unsig_nbr(unsigned int n)
{
	char			c;
	int				len;
	unsigned int	n1;

	n1 = n;
	if (n1 < 0)
		n1 = 4294967296 + n1;
	len = ft_u_len(n1);
	if (n1 < 10)
	{
		c = n1 + '0';
		write (1, &c, 1);
	}
	else
	{
		ft_put_unsig_nbr(n1 / 10);
		c = (n1 % 10) + '0';
		write(1, &c, 1);
	}
	return (len);
}
