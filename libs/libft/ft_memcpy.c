/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:17:14 by psydenst          #+#    #+#             */
/*   Updated: 2022/05/27 16:16:59 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dest;
	s = src;
	if ((len == 0) || (src == dest))
	{
		return (dest);
	}
	i = 0;
	while (i < len)
	{
		*d++ = *s++;
		i++;
	}
	return (dest);
}
