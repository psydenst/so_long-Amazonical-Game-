/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:33:22 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/07 16:58:07 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	keyhook_main(int keycode, t_map *map)
{
	if (keycode != 53)
		map->moves++;
	if (keycode == 13)
		keyhook_w(map);
	if (keycode == 0)
		keyhook_a(map);
	if (keycode == 1)
		keyhook_s(map);
	if (keycode == 2)
		keyhook_d(map);
	if (keycode == 53)
		keyhook_esc(map);
	return (0);
}

int	close_window(t_map *map)
{
	exit_func(map, "You closed the window with 🅧 ");
	return (0);
}

void	exit_func(t_map *map, const char *str)
{
	ft_printf("%s\n", str);
	if (map->mlx_win)
		mlx_clear_window(map->mlx_ptr, map->mlx_win);
	if (map->mlx_ptr)
		mlx_clear_window(map->mlx_ptr, map->mlx_win);
	exit_images(map);
	if (map->mlx_win)
		mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	if (map->mlx_ptr)
		free(map->mlx_ptr);
	if (map->map)
		free_map(map->map);
	exit(0);
}

void	exit_images(t_map *map)
{
	if (map->wall)
		mlx_destroy_image(map->mlx_ptr, map->wall);
	if (map->floor)
		mlx_destroy_image(map->mlx_ptr, map->floor);
	if (map->collect)
		mlx_destroy_image(map->mlx_ptr, map->collect);
	if (map->player)
		mlx_destroy_image(map->mlx_ptr, map->player);
	if (map->exit)
		mlx_destroy_image(map->mlx_ptr, map->exit);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free (map);
}
