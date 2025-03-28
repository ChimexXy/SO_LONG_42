/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 06:33:25 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/28 05:12:00 by mozahnou         ###   ########.fr       */
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
	if (!map_flood(game))
		return (0);
	return (1);
}

void print_map(char **map_cpy)
{
	int x;
	int y = 0;
	while(map_cpy[y])
	{
		x = 0;
		while(map_cpy[y][x])
		{
			printf("%c", map_cpy[y][x]);
			x++;
		}
		y++;
	}
}

int	map_flood(x_game *game)
{
	char	**map_cpy;
	int		i;
	int		x;
	int		y;

	map_cpy = malloc(sizeof(char *) * game->wid_line);
	i = 0;
	while(game->map[i])
	{
		map_cpy[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_cpy[i] = NULL;
	set_player_position(game);
	x = game->player_pos_x;
	y = game->player_pos_y;
	flood_fill(map_cpy, x, y);
	
	if (!check_new_map(map_cpy))
		return (0);
	// free_double_pointer(map_cpy);
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	x_game	*game;
	mlx_s *mlx;

	if (ac != 2)
	{
		write(1 ,"Number of arguments is not enought\n", 35);
		exit(1);
	}
	game = malloc(sizeof(x_game));
	mlx = malloc(sizeof(mlx_s));
	fd = open(av[1], O_RDONLY);

	if (fd == -1 || !map_checking(av[1], game, fd))
	{
		free(game);
		exit (1);
	}
	window_open(mlx, game);
	close(fd);
}
