/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:33:07 by psydenst          #+#    #+#             */
/*   Updated: 2022/05/27 16:48:45 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (n-- != 0)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - s2[i]);
		if (s1[i] == 0)
			break ;
		i++;
	}
	return (0);
}
