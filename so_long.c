/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 06:33:25 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/23 02:53:15 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checking(char *av, x_game *game, int fd)
{
	if (!av)
		return (0);
	if (!check_name(av))
		return (0);
	if (!map_read_line(av, game, fd))
		return (0);
	if (!map_check_len(game))
		return (0);
	if (!wall_check1(game))
		return (0);
	if (!join_map(game))
		return (0);
	if (!map_checker_param(game))
	{
		write(1, "Map not valid\n", 14);
		return (0);
	}
	if (!map_checker_param2(game))
		return (0);
	return (1);
}

int	map_flood(x_game *game)
{
	char	**map_cpy;
	int		i;

	map_cpy = malloc(sizeof(char *) * game->wid_line);
	i = 0;
	while(game->map[i])
	{
		map_cpy[i] = ft_strdup(game->map[i]);
		i++;
	}
	flood_fill(game, map_cpy);
}

int main(int ac, char **av)
{
	int	fd;
	x_game  *game;

	if (ac != 2)
	{
		write(1 ,"Number of arguments is not enought\n", 35);
		exit(1);
	}
	game = malloc(sizeof(x_game));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		free(game);
		exit (1);
	}
	if (!map_checking(av[1], game, fd))
	{
		free(game);
		exit (1);
	}
	map_flood(game);
	close(fd);
}