/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 06:33:25 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/30 02:04:21 by mozahnou         ###   ########.fr       */
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

int	map_flood(x_game *game)
{
	char	**map_cpy;
	int		i;
	int		x;
	int		y;

	map_cpy = malloc(sizeof(char *) * game->wid_line + 1);
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
	{
		free_double_pointer(map_cpy);
		return (0);
	}
	free_double_pointer(map_cpy);

	return (1);
}

void	select_things(mlx_s *mlx,x_game *game)
{
	int	i;

	mlx->map = malloc(sizeof(char *) * game->wid_line + 1);
	i = 0;
	while(game->map[i])
	{
		mlx->map[i] = ft_strdup(game->map[i]);
		i++;
	}
	mlx->map[i] = NULL;
	mlx->x_p = game->player_pos_x;
	mlx->y_p = game->player_pos_y;
	mlx->count_coin = game->coin;
	mlx->len_line = game->len_line;
	mlx->wid_line = game->wid_line;
	mlx->img_wid = 31;
	mlx->img_len = 31;
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
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || !map_checking(av[1], game, fd))
	{
		free(game);
		exit (1);
	}
	mlx = malloc(sizeof(mlx_s));
	select_things(mlx, game);
	free_double_pointer(game->map);
	free(game);
	window_open(mlx);
	free_double_pointer(game->map);
	close(fd);
}
