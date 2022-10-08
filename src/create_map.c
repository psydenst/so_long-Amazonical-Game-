/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:32:42 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/07 19:42:54 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	open_window(t_map *map)
{
	upload_imgs(map);
	map->mlx_win = mlx_new_window(map->mlx_ptr, map->window_width * PIXEL,
			(map->window_height + 1) * PIXEL, "Amazonical Game");
	render_map(map);
}

void	upload_imgs(t_map *map)
{
	map->img_width = PIXEL;
	map->img_height = PIXEL;
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr, WALL,
			&map->img_width, &map->img_height);
	map->floor = mlx_xpm_file_to_image(map->mlx_ptr, FLOOR,
			&map->img_width, &map->img_height);
	map->collect = mlx_xpm_file_to_image(map->mlx_ptr, COLLECT,
			&map->img_width, &map->img_height);
	map->player = mlx_xpm_file_to_image(map->mlx_ptr, PLAYER,
			&map->img_width, &map->img_height);
	map->exit = mlx_xpm_file_to_image(map->mlx_ptr, EXIT,
			&map->img_width, &map->img_height);
}

void	ft_create_map(t_map *map)
{
	char	*str;
	char	*joker;
	int		len;

	map->lines = 0;
	str = NULL;
	joker = get_next_line(map->fd);
	len = ft_strlen(joker);
	map->window_width = len - 1;
	map->map = ft_calloc(len + 1, sizeof(char *));
	if (!map->map)
		write(1, "Error with map->map", 19);
	while (1)
	{
		str = get_next_line(map->fd);
		if (str == NULL)
			break ;
		joker = ft_strjoin(joker, str);
		map->lines++;
	}
	free(str);
	close(map->fd);
	ft_validate_count(joker, map);
}

void	ft_validate_count(char *joker, t_map *map)
{
	map->window_height = map->lines;
	map->map = ft_split(joker, '\n');
	free(joker);
	if (counter(map) == 1)
		open_window(map);
	else
	{
		ft_printf("Invalid map!");
		exit(0);
	}
}
