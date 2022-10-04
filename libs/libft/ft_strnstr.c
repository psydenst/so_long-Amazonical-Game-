/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:48:56 by psydenst          #+#    #+#             */
/*   Updated: 2022/05/27 16:50:02 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *neddle, size_t len)
{
	int		i;
	size_t	j;
	size_t	z;

	i = 0;
	j = 0;
	z = 0;
	if (neddle[j] == '\0')
		return (((char *)haystack));
	while (haystack[i] != '\0' && z < len)
	{
		while (haystack[i + j] == neddle[j] && haystack[i + j] != '\0'
			&& (i + j) < len)
		{
			j++;
			if (neddle[j] == '\0')
				return (((char *) haystack + i));
		}
			i++;
			z++;
			j = 0;
	}
	return (0);
}
