/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:42:52 by psydenst          #+#    #+#             */
/*   Updated: 2022/09/30 19:55:04 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	int	fd;

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
	ft_create_map(fd);
}
