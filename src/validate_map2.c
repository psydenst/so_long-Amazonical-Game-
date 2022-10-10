/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:57:55 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/07 18:03:34 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	values(t_map *map)
{
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->counter_x = 0;
	map->counter_y = 0;
}

int	char_counter(t_map *map)
{
	values(map);
	while (map->map[map->counter_x])
	{
		map->counter_y = 0;
		while (map->map[map->counter_x][map->counter_y])
		{
			if (map->map[map->counter_x][map->counter_y] != '1'
				&& map->map[map->counter_x][map->counter_y] != '0'
				&& map->map[map->counter_x][map->counter_y] != 'C'
				&& map->map[map->counter_x][map->counter_y] != 'E'
				&& map->map[map->counter_x][map->counter_y] != 'P'
				&& map->map[map->counter_x][map->counter_y] != '\n')
				return (0);
			map->counter_y++;
		}
	map->counter_x++;
	}
	map->counter_x = 0;
	map->counter_y = 0;
	if (char_counter2(map) == 1)
		return (1);
	else
		return (0);
}

int	char_counter2(t_map *map)
{
	while (map->map[map->counter_x])
	{
		map->counter_y = 0;
		while (map->map[map->counter_x][map->counter_y])
		{
			if (map->map[map->counter_x][map->counter_y] == 'P')
			{
				map->player_x = map->counter_x;
				map->player_y = map->counter_y;
				map->p_count++;
			}
			if (map->map[map->counter_x][map->counter_y] == 'E')
				map->e_count++;
			if (map->map[map->counter_x][map->counter_y] == 'C')
				map->c_count++;
			map->counter_y++;
		}
	map->counter_x++;
	}
	if (map->p_count == 1 && map->e_count == 1)
		return (1);
	else
		return (ft_printf("Error\nYour map contains duplicate characters\n"));
}
