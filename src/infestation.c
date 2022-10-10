/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infestation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:09:03 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/10 15:18:25 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int start_infestation(t_map *map)
{
    int i;
    int fd;
    char **map_copy;
    map->coins_possible = map->c_count;
    map_copy = calloc(map->window_width + 1, sizeof(char *));
    if (!map_copy)
        return (0);
    fd = open(map->map_path, O_RDONLY);
    if (fd < 0)
        return (0);
    i = 0;
    while (i <= map->window_width)
    {
        map_copy[i] = get_next_line(fd);
        i++;
    }
    map->exit_possible = 0;
    infestation(map_copy, map->player_x, map->player_y, map);
    free(map->map_path);
    return (1);
}

int infestation(char **map_copy, int x, int y, t_map *map)
{
    if ((map_copy[x - 1][y] == 'E'|| map_copy[x + 1][y] == 'E' ||
    map_copy[x][y - 1] == 'E' || map_copy[x - 1][y] == 'E'))
        map->exit_possible++;
    if (map_copy[x][y] == 'C')
        map->coins_possible--;
    if (map_copy[x][y] != '1' && map_copy[x][y] != 'P')
        map_copy[x][y] = 'P';
    if (map_copy[x - 1][y] != '1' && map_copy[x - 1][y] != 'P')
        infestation(map_copy, x - 1, y, map);
    if (map_copy[x + 1][y] != '1' && map_copy[x + 1][y] != 'P')
        infestation(map_copy, x + 1, y, map);     
    if (map_copy[x][y - 1] != '1' && map_copy[x][y - 1] != 'P')
        infestation(map_copy, x, y - 1, map);
    if (map_copy[x][y + 1] != '1' && map_copy[x][y + 1] != 'P')
        infestation(map_copy, x, y + 1, map);
	if (map->coins_possible == 0 && map->exit_possible != 0)
        return (1);
    else
        return (0);
}
