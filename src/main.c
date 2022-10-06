/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:42:52 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/05 17:52:46 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	int	fd;
	t_map map;

	if (argc != 2)
	{
		printf("Invalid arguments!");
		exit (0);
	}
	if (validate_ber(argv[1]) == 0)
	{
		ft_printf("Not a .ber");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(1, "Error with map path!\n", 21));
	map.mlx_ptr = mlx_init();
	ft_create_map(fd, &map);
	mlx_key_hook(map.mlx_win, keyhook_main, &map);
	mlx_hook(map.mlx_win, 17, 0, close_window, &map);
	mlx_loop(map.mlx_ptr);
}
