/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_teste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:21:22 by psydenst          #+#    #+#             */
/*   Updated: 2022/09/19 20:32:30 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"

int main()
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_tree;
	void	*img_floor;
	void	*img_coin;
	void	*img_player;
	int x = 32;
	int y = 32;
	
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1500, 1200, "Hello World!");
	
	img_tree = mlx_xpm_file_to_image(mlx_ptr, "img/img_converted/tree_1_48x48.xpm", &x, &y);
	img_floor = mlx_xpm_file_to_image(mlx_ptr, "img/img_converted/floor_48x48.xpm", &x, &y);
	img_coin = mlx_xpm_file_to_image(mlx_ptr, "img/img_converted/capy_48x48.xpm", &x, &y);
	img_player = mlx_xpm_file_to_image(mlx_ptr, "img/img_converted/Jaguar_48x48.xpm", &x, &y);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img_tree, 0, 0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img_floor, 48, 0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img_coin, 96, 0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img_player, 144, 0);
	mlx_loop(mlx_ptr);
}

