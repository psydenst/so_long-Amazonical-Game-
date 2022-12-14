/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:42:52 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/07 20:24:15 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	map.moves = 0;
	if (argc != 2)
	{
		ft_printf("Error\nInvalid arguments!");
		exit (0);
	}
	map.map_path = ft_strdup(argv[1]);
	if (validate_ber(argv[1]) == 0)
	{
		ft_printf("Error\nNot a .ber");
		return (0);
	}
	map.fd = open(argv[1], O_RDONLY);
	if (map.fd < 0)
		return (ft_printf("Error\n Error with map path!\n"));
	map.mlx_ptr = mlx_init();
	ft_create_map(&map);
	mlx_key_hook(map.mlx_win, keyhook_main, &map);
	mlx_hook(map.mlx_win, 17, 0, close_window, &map);
	mlx_loop(map.mlx_ptr);
}
