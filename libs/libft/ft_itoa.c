/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:18:46 by psydenst          #+#    #+#             */
/*   Updated: 2022/05/27 16:12:39 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_string(char *x, unsigned int number, long int len, int sign)
{
	while (len >= 0)
	{
		x[len--] = '0' + (number % 10);
		number = number / 10;
	}
	if (sign < 0)
		x[0] = '-';
	return (x);
}

static long int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*x;
	long int		len;
	unsigned int	number;
	int				sign;

	number = n;
	sign = 1;
	len = ft_len(n);
	x = malloc((len + 1) * sizeof(char));
	if (!(x))
		return (NULL);
	x[len--] = '\0';
	if (n == 0)
		x[0] = '0';
	if (n < 0)
	{
		sign = sign * -1;
		number = n * -1;
		x = ft_string(x, number, len, sign);
		return (x);
	}
	else if (n > 0)
		number = n;
		x = ft_string(x, number, len, sign);
	return (x);
}
