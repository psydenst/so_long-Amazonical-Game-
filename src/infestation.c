/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infestation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:09:03 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/07 23:13:43 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int start_infestation(t_map *map)
{
    int i;
    int fd;
    char **map_copy;
    map->coins_map_cpy = map->c_count;

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
    infestation(map, map->player_x, map->player_y, map_copy);
    validate_map_path(map, map_copy);
    free(map->map_path);
    return (1);
}

// void	infestation(t_map *map, int x, int y, char **map_copy)
// {
// 	if (map_copy[x][y] == '1' || map_copy[x][y] == 'X')
// 		return ;
// 	if (map_copy[x][y - 1] == 'E' || map_copy[x][y + 1] == 'E' ||
// 			map_copy[x - 1][y] == 'E' ||
// 			map_copy[x + 1][y] == 'E' || map_copy[x][y] == 'E' )
// 		map->exit_posible++;
// 	if (map_copy[x][y] != '1')
// 		map_copy[x][y] = '1';
// 	if (map_copy[x][y - 1] != '1' && map_copy[x][y - 1] != 'X'
// 			&& map_copy[x][y - 1] != 'E')
// 		infestation(map, x, y - 1, map_copy);
// 	if (map_copy[x][y + 1] != '1' && map_copy[x][y + 1] != 'X' &&
// 			map_copy[x][y + 1] != 'E')
// 		infestation(map, x, y + 1, map_copy);
// 	if (map_copy[x - 1][y] != '1' && map_copy[x - 1][y] != 'X' &&
// 			map_copy[x - 1][y] != 'E')
// 		infestation(map, x - 1, y, map_copy);
// 	if (map_copy[x + 1][y] != '1' && map_copy[x + 1][y] != 'X' &&
// 			map_copy[x + 1][y] != 'E')
// 		infestation(map, x + 1, y, map_copy);
// 	return ;
// }

// void	validate_map_path(t_map *map, char **map_copy)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	if (map->exit_posible != 1)
// 		exit_func(map, "Error!\n No valid map path...");
// 	while (map_copy[i] != NULL)
// 	{
// 		j = 0;
// 		while (map_copy[i][j] != '\0')
// 		{
// 			if (map_copy[i][j] == 'C')
// 				exit_func(map, "Error!\n No valid map path...");
// 			j++;
// 		}
// 		i++;
// 	}
// 	return ;
// }






// int infestation(char **map_copy, int player_x, int player_y, int coins)
// {
//     if ((map_copy[player_x - 1][player_y] == 'E'|| map_copy[player_x + 1][player_y] == 'E' ||
//     map_copy[player_x][player_y - 1] == 'E' || map_copy[player_x - 1][player_y] == 'E') &&
//     coins == 0)
//     {
//         return (2);
//     }
//     if (map_copy[player_x - 1][player_y] != '1' && map_copy[player_x - 1][player_y] != 'P')
//     {
//         if (map_copy[player_x - 1][player_y] == 'C')
//             coins--;
//         map_copy[player_x - 1][player_y] = 'P';
//         player_x = player_x - 1;
//         infestation(map_copy, player_x, player_y, coins);       
//     }
//     if (map_copy[player_x + 1][player_y] != '1' && map_copy[player_x + 1][player_y] != 'P')
//     {
//         if (map_copy[player_x + 1][player_y] == 'C')
//             coins--;
//         map_copy[player_x + 1][player_y] = 'P';
//         player_x = player_x + 1;
//         infestation(map_copy, player_x, player_y, coins);     
//     }
//     infestation_horizontal(map_copy, player_x, player_y, coins);
    
 
 
//     int i = 0;
// 	while (map_copy[i])
// 	{
// 		ft_printf("Valor de map_copy[%i] é %s\n", i, map_copy[i]);
// 		i++;
// 	}
//     ft_printf("Valor de coins é: %i\n", coins);
// 	return (1);
// }

// int infestation_horizontal(char **map_copy, int player_x, int player_y, int coins)
// {
//     if (map_copy[player_x][player_y - 1] != '1' && map_copy[player_x][player_y - 1] != 'P')
//     {
//         if (map_copy[player_x][player_y - 1] == 'C')
//             coins--;
//         map_copy[player_x][player_y - 1] = 'P';
//         player_y = player_y - 1;
//         infestation(map_copy, player_x, player_y, coins);      
//     }
//     if (map_copy[player_x][player_y + 1] != '1' && map_copy[player_x][player_y + 1] != 'P')
//     {
//         if (map_copy[player_x][player_y + 1] == 'C')
//             coins--;
//         map_copy[player_x][player_y + 1] = 'P';
//         player_y = player_y + 1;
//         infestation(map_copy, player_x, player_y, coins);       
//     }
//     return (1);
// }