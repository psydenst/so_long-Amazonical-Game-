/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:12:25 by psydenst          #+#    #+#             */
/*   Updated: 2022/05/27 16:00:56 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	nb;
	void	*p;
	char	*q;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	nb = count * size;
	p = malloc(nb);
	if (!p)
		return (NULL);
	q = (void *)p;
	i = 0;
	while (i < nb)
	{
		*q++ = '\0';
		i++;
	}
	return (p);
}
