/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:17:44 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/07 23:11:20 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL "./img/img_converted/tree_1_48x48.xpm"
# define FLOOR "./img/img_converted/floor_48x48_2.xpm"
# define COLLECT "./img/img_converted/capy_60x60.xpm"
# define PLAYER "./img/img_converted/Jaguar_35x35.xpm"
# define EXIT "./img/img_converted/door_48x48.xpm"
# define PIXEL 48

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct s_map
{
	int		lines;
	char	**map;
	void	*wall;
	void	*floor;
	void	*collect;
	void	*player;
	void	*exit;
	int		img_width;
	int		img_height;
	int		axis_x;
	int		axis_y;
	int		p_count;
	int		e_count;
	int		c_count;
	int		player_x;
	int		player_y;
	void	*mlx_ptr;
	void	*mlx_win;
	int		window_width;
	int		window_height;
	int		counter_x;
	int		counter_y;
	int		fd;
	int		coins_map_cpy;
	char	*map_path;
	int 	exit_posible;
}	t_map;

// CREATE_MAP.C
void		open_window(t_map *map);
void		upload_imgs(t_map *map);
void		ft_create_map(t_map *map);
void		ft_validate_count(char *joker, t_map *map);

// CREATE_MAP2.C
void		render_map(t_map *map);
void		render_map2(t_map *map);
int			validate_ber(char *map_name);

// VALIDATE_MAP.C
int			wall_check(t_map *map);
int			wall_check2(t_map *map);
int			counter(t_map *map);
int			ft_is_rectangle(t_map *map);

// INFESTATION.C
int			start_infestation(t_map *map);
void	infestation(t_map *map, int x, int y, char **map_copy);
void		validate_map_path(t_map *map, char **map_copy);
// VALIDATE_MAP2.C
int			ft_is_ber(char *haystack);
void		values(t_map *map);
int			char_counter(t_map *map);
int			char_counter2(t_map *map);

// KEY_EVENTS.C
int			keyhook_main(int keycode, t_map *map);
void		exit_func(t_map *map, const char *str);
void		exit_images(t_map *map);
void		free_map(char **map);
int			close_window(t_map *map);

// ASDW.C
int			keyhook_w(t_map *map);
int			keyhook_d(t_map *map);
int			keyhook_a(t_map *map);
int			keyhook_s(t_map *map);
int			keyhook_esc(t_map *map);

#endif
