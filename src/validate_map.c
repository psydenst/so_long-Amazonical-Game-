/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:04:47 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/04 20:20:55 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	validate_ber(char *map_name)
{
	int		a;
	int		b;
	int		x;
	char	*haystack;

	a = 4;
	x = 0;
	if (ft_strlen(map_name) < 5)
		return (0);
	b = ft_strlen(map_name) - 4;
	haystack = malloc(5 * sizeof(char));
	while (a > 0)
	{
		haystack[x] = map_name[b];
		x++;
		b++;
		a--;
	}
	if (ft_is_ber(haystack) == 1)
		return (1);
	else
		return (0);
}

int	ft_is_ber(char *haystack)
{
	if (ft_strnstr(haystack, ".ber", 4))
	{
		free(haystack);
		return (1);
	}
	else
	{
		free(haystack);
		return (0);
	}
}

int	counter(t_map *map)
{
	int	x;

	x = 0;
	while (map->map[x])
	{
		if (ft_strchr(map->map[x], 'P') == 0 && ft_strchr(map->map[x], '0') == 0
			&& ft_strchr(map->map[x], '1') == 0
			&& ft_strchr(map->map[x], 'C') == 0
			&& ft_strchr(map->map[x], 'E') == 0)
			return (0);
		x++;
	}
	if (char_counter(map) && wall_check(map) && ft_is_rectangle(map))
		return (1);
	else
		return (0);
}

int	char_counter(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->p_count = 0;
	map->e_count = 0;
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
		{
			if (map->map[x][y] != '1'
				&& map->map[x][y] != '0'
				&& map->map[x][y] != 'C' && map->map[x][y] != 'E'
				&& map->map[x][y] != 'P' && map->map[x][y] != '\n')
				return (0);
			if (map->map[x][y] == 'P')
				map->p_count++;
			if (map->map[x][y] == 'E')
				map->e_count++;
			y++;
		}
	x++;
	}
	if (map->p_count == 1 && map->e_count == 1)
		return (1);
	else
		return (0);
}

int	wall_check(t_map *map)
{
	int y;

	y = 0;
	while (map->map[0][y])
	{
		if(map->map[0][y] != '1')
			return (0);
		y++;
	}
	y = 0;
	while (map->map[map->window_height][y])
	{
		if (map->map[map->window_height][y] != '1')
			return (0);
		y++;
	}
	y = 0;
	while (map->map[y]) 
	{
		if (map->map[y][0] != '1')
			return (0);
		y++;
	}
	y = 0;
	while (map->map[y]) 
	{
		if (map->map[y][ft_strlen(map->map[y]) - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	ft_is_rectangle(t_map *map)
{
	size_t	x;
	size_t	y;
	
	if (map->map == NULL)
		return (0);
	x = 0;
	y = ft_strlen(map->map[x]);
	while (map->map[x])
	{
		if (ft_strlen(map->map[x]) != y)
			return (0);
		x++;
	}
	return (1);
}
