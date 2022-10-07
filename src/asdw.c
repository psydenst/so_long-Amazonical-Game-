/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asdw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:20:44 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/07 16:31:51 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	keyhook_w(t_map *map)
{
	if (map->map[map->player_x - 1][map->player_y] == '1')
		return (0);
	if (map->map[map->player_x - 1][map->player_y] == 'E')
	{
		if (map->c_count == 0)
			exit_func(map, "");
		else
			return (0);
	}
	if (map->map[map->player_x - 1][map->player_y] == 'C' ||
			map->map[map->player_x - 1][map->player_y] == '0')
	{
		if (map->map[map->player_x - 1][map->player_y] == 'C')
			map->c_count--;
		map->map[map->player_x - 1][map->player_y] = 'P';
		map->map[map->player_x][map->player_y] = '0';
		map->player_x = map->player_x - 1;
	}
	render_map(map);
	return (0);
}

int	keyhook_d(t_map *map)
{
	if (map->map[map->player_x][map->player_y + 1] == '1')
		return (0);
	if (map->map[map->player_x][map->player_y + 1] == 'E')
	{
		if (map->c_count == 0)
			exit_func(map, "");
		else
			return (0);
	}
	if (map->map[map->player_x][map->player_y + 1] == 'C' ||
			map->map[map->player_x][map->player_y + 1] == '0')
	{
		if (map->map[map->player_x][map->player_y + 1] == 'C')
			map->c_count--;
		map->map[map->player_x][map->player_y + 1] = 'P';
		map->map[map->player_x][map->player_y] = '0';
		map->player_y = map->player_y + 1;
	}
	render_map(map);
	return (0);
}

int	keyhook_a(t_map *map)
{
	if (map->map[map->player_x][map->player_y - 1] == '1')
		return (0);
	if (map->map[map->player_x][map->player_y - 1] == 'E')
	{
		if (map->c_count == 0)
			exit_func(map, "");
		else
			return (0);
	}
	if (map->map[map->player_x][map->player_y - 1] == 'C' ||
			map->map[map->player_x][map->player_y - 1] == '0')
	{
		if (map->map[map->player_x][map->player_y - 1] == 'C')
			map->c_count--;
		map->map[map->player_x][map->player_y - 1] = 'P';
		map->map[map->player_x][map->player_y] = '0';
		map->player_y = map->player_y - 1;
	}
	render_map(map);
	return (0);
}

int	keyhook_s(t_map *map)
{
	if (map->map[map->player_x + 1][map->player_y] == '1')
		return (0);
	if (map->map[map->player_x + 1][map->player_y] == 'E')
	{
		if (map->c_count == 0)
			exit_func(map, "");
		else
			return (0);
	}
	if (map->map[map->player_x + 1][map->player_y] == 'C' ||
			map->map[map->player_x + 1][map->player_y] == '0')
	{
		if (map->map[map->player_x + 1][map->player_y] == 'C')
			map->c_count--;
		map->map[map->player_x + 1][map->player_y] = 'P';
		map->map[map->player_x][map->player_y] = '0';
		map->player_x = map->player_x + 1;
	}
	render_map(map);
	return (0);
}

int	keyhook_esc(t_map *map)
{
	exit_func(map, "You have pressed esc");
	return (0);
}
