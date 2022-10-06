/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:17:44 by psydenst          #+#    #+#             */
/*   Updated: 2022/10/05 17:49:32 by psydenst         ###   ########.fr       */
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
	int	lines;
	char	**map;
	void	*wall;
	void	*floor;
	void	*collect;
	void	*player;
	void	*exit;
	int     img_width;
	int     img_height;
	int     axis_x;
	int    	axis_y;
	int	p_count;
	int	e_count;
	int	c_count;
	int	player_x;
	int	player_y;
	void	*mlx_ptr;
	void	*mlx_win;
	int	window_width;
	int	window_height;

} t_map;

// CREATE_MAP.C
void		open_window(t_map *map);
void		upload_imgs(t_map *map);
void		ft_create_map(int fd, t_map *map);
void		render_map(t_map *map);
void		ft_validate_count(char *joker, t_map *map);

// VALIDATE_MAP.C
int		validate_ber(char *map_name);
int		wall_check(t_map *map);
int		char_counter(t_map *map);
int 	counter(t_map *map);
int		ft_is_rectangle(t_map *map);
int		ft_is_ber(char *haystack);
// UTILS.C
// int			get_height(int fd);
// int			ft_strlen_int(const char *s);

// KEY EVENTS
int	keyhook_main(int keycode, t_map *map);
int	keyhook_esc(t_map *map);
void	exit_func(t_map *map, const char *str);
void	exit_images(t_map *map);
void    exit_window(t_map *map);
void	free_map(char **map);
int	close_window(t_map *map);
int     keyhook_w(t_map *map);
// void	exit_window(t_map *map);
#endif
