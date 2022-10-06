/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:33:22 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/06 19:37:43 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	keyhook_main(int keycode, t_map *map)
{
	 if (keycode == 13)
	 {
		keyhook_w(map);
	 }
	// if (keycode == 0)
	// {
	// 	keyhook_a();
	// }
	// if (keycode == 1)
	// {
	// 	keyhook_s();
	// }
	// if (keycode == 2)
	// {
	// 	keyhook_d();
	// }
	if (keycode == 53)
	{
		keyhook_esc(map);
	}
	return (0);
}

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
	if (map->map[map->player_x - 1][map->player_y] == 'C' || map->map[map->player_x - 1][map->player_y] == '0')
	{
		if (map->map[map->player_x - 1][map->player_y] == 'C')
			map->c_count--;
		map->map[map->player_x - 1][map->player_y] = 'P';
		map->map[map->player_x][map->player_y] = '0';
	}
	int i = 0;
	while(i < 5)
	{
		printf("Position map->map: = %s\n", map->map[i]);
		i++;
	}
	render_map(map);
	return (0);
}

int keyhook_esc(t_map *map)
{
        exit_func(map, "You have pressed esc");
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
	if(map->mlx_win)
		mlx_clear_window(map->mlx_ptr, map->mlx_win);
	if(map->mlx_ptr)
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
	// if (map.exit_closed)
	// 	mlx_destroy_image(, player);
	// if (map.enemy)
	// 	mlx_destroy_image(, enemy); BONUS OPTIONS;
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
