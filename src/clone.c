void	validate_map(t_data *s_data, char *map)
{
	map_validate_name(s_data, map);
	map_validate_dimentions(s_data);
	map_validate_outline(s_data);
	validate_components(s_data);
	s_data->map_array = create_map_array(s_data);
	dfs(s_data, s_data->player_x, s_data->player_y, s_data->map_array);
	validate_map_path(s_data);
	free_map_array(s_data->map_array);
	s_data->map_array = create_map_array(s_data);
	return ;
}

void	validate_map_path(t_data *s_data)
{
	int	i;
	int	j;

	i = 0;
	if (s_data->e_reach <= 0 )
		exit_func(s_data, "Error!\nThere is no valid path");
	while (i < s_data->size_y)
	{
		j = 0;
		while (j < s_data->size_x)
		{
			if (s_data->map_array[i][j] == 'C')
				exit_func(s_data, "Error!\nThere is no valid path");
			j++;
		}
		i++;
	}
	return ;
}

char	**create_map_array(t_data *s_data)
{
	int		i;
	int		fd;
	char	**array;

	array = ft_calloc(s_data->size_y + 1, sizeof(char *));
	if (!array)
		return (NULL);
	fd = open(s_data->map_name, O_RDONLY);
	if (fd < 2)
		return (NULL);
	i = 0;
	while (i <= s_data->size_y)
	{
		array[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (array);
}

void	dfs(t_data *s_data, int x, int y, char **map_sol)
{
	if (map_sol[x][y] == '1' || map_sol[x][y] == 'X')
		return ;
	if (map_sol[x][y - 1] == 'E' || map_sol[x][y + 1] == 'E' ||
			map_sol[x - 1][y] == 'E' ||
			map_sol[x + 1][y] == 'E' || map_sol[x][y] == 'E' )
		s_data->e_reach++;
	if (map_sol[x][y] != '1')
		map_sol[x][y] = '1';
	if (map_sol[x][y - 1] != '1' && map_sol[x][y - 1] != 'X'
			&& map_sol[x][y - 1] != 'E')
		dfs(s_data, x, y - 1, map_sol);
	if (map_sol[x][y + 1] != '1' && map_sol[x][y + 1] != 'X' &&
			map_sol[x][y + 1] != 'E')
		dfs(s_data, x, y + 1, map_sol);
	if (map_sol[x - 1][y] != '1' && map_sol[x - 1][y] != 'X' &&
			map_sol[x - 1][y] != 'E')
		dfs(s_data, x - 1, y, map_sol);
	if (map_sol[x + 1][y] != '1' && map_sol[x + 1][y] != 'X' &&
			map_sol[x + 1][y] != 'E')
		dfs(s_data, x + 1, y, map_sol);
	return ;
}


// void	infestation(t_map *map, int x, int y, char **map_copy)
// {
// 	if (map_copy[x][y] == '1')
// 		return ;
// 	if (map_copy[x][y - 1] == 'E' || map_copy[x][y + 1] == 'E' ||
// 			map_copy[x - 1][y] == 'E' ||
// 			map_copy[x + 1][y] == 'E' || map_copy[x][y] == 'E' )
// 		map->exit_possible++;
// 	if (map_copy[x][y] != 'P')
// 		map_copy[x][y] = 'P';
// 	if (map_copy[x][y - 1] != '1' && map_copy[x][y - 1] != 'E')
// 		infestation(map, x, y - 1, map_copy);
// 	if (map_copy[x][y + 1] != '1' && map_copy[x][y + 1] != 'E')
// 		infestation(map, x, y + 1, map_copy);
// 	if (map_copy[x - 1][y] != '1' && map_copy[x - 1][y] != 'E')
// 		infestation(map, x - 1, y, map_copy);
// 	if (map_copy[x + 1][y] != '1' && map_copy[x + 1][y] != 'E')
// 		infestation(map, x + 1, y, map_copy);
//     int i = 0;
//     while(i < 5)
//     {
//         printf("%s", map_copy[i]);
//         i++;
//     }
//     return ;
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