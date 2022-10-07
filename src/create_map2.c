/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:51:04 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/07 16:55:20 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_map(t_map *map)
{
	map->axis_x = 0;
	map->axis_y = 0;
	while (map->map[map->axis_x] != NULL)
	{
		if (map->map[map->axis_x][map->axis_y] == '1')
		{
			mlx_put_image_to_window(map->mlx_ptr, map->mlx_win,
				map->floor, (map->axis_y * PIXEL), (map->axis_x * PIXEL));
			mlx_put_image_to_window(map->mlx_ptr, map->mlx_win,
				map->wall, (map->axis_y * PIXEL), (map->axis_x * PIXEL));
		}
		else if (map->map[map->axis_x][map->axis_y] != '1')
			mlx_put_image_to_window(map->mlx_ptr, map->mlx_win,
				map->floor, (map->axis_y * PIXEL), (map->axis_x * PIXEL));
		if (map->map[map->axis_x][map->axis_y] == '\0')
		{
			map->axis_x++;
			map->axis_y = -1;
		}
		map->axis_y++;
	}
	render_map2(map);
}

void	render_map2(t_map *map)
{
	map->axis_x = 0;
	map->axis_y = 0;
	while (map->map[map->axis_x] != NULL)
	{
		if (map->map[map->axis_x][map->axis_y] == 'P')
			mlx_put_image_to_window(map->mlx_ptr, map->mlx_win,
				map->player, (map->axis_y * PIXEL), (map->axis_x * PIXEL));
		if (map->map[map->axis_x][map->axis_y] == 'C')
			mlx_put_image_to_window(map->mlx_ptr, map->mlx_win,
				map->collect, (map->axis_y * PIXEL), (map->axis_x * PIXEL));
		if (map->map[map->axis_x][map->axis_y] == 'E')
			mlx_put_image_to_window(map->mlx_ptr, map->mlx_win,
				map->exit, (map->axis_y * PIXEL), (map->axis_x * PIXEL));
		if (map->map[map->axis_x][map->axis_y] == '\0')
		{
			map->axis_x++;
			map->axis_y = -1;
		}
		map->axis_y++;
	}
}

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
