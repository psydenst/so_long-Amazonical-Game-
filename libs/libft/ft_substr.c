/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:39:25 by psydenst          #+#    #+#             */
/*   Updated: 2022/05/27 16:57:05 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*cpy;
	unsigned int	j;

	i = 0;
	while (i <= len)
		i++;
	cpy = ft_calloc(i, 1);
	if (cpy == 0 || !cpy)
		return (NULL);
	if (start >= ft_strlen(s))
		return ((char *)cpy);
	j = 0;
	i = start;
	while (start < i + len)
	{
		((char *)cpy)[j] = s[start];
		start++;
		j++;
	}
	((char *)cpy)[j] = '\0';
	return ((char *)cpy);
}
