/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 06:33:25 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/22 19:32:59 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	int	fd;
	x_game  *game;

	game = malloc(sizeof(x_game));
	if (ac != 2)
	{
		ft_printf("Number of arguments is not enought\n");
		exit(1);
	}
	else
		check_name(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	map_read_line(av[1], game, fd);
	map_check_len(game);
	wall_check(game);
	join_map(game);
	map_checker_param(game);
	map_checker_param2(game);
	close(fd);
}