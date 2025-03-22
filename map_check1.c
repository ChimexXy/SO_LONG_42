/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:50:11 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/22 21:24:11 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32 || str[i] == '\t')
			return (0);
		i++;
	}
	return (1);
}

void check_name(char *av1)
{
	int i;
	int	j;
	char **name;

	if (check_space(av1) == 0 || !av1)
		return ;
	j = ft_count_word(av1, '/') - 1;
	name = ft_split(av1, '/');
	i = ft_strlen(name[j]);
	if (name[j][i - 1] == 'r' && name[j][i - 2] == 'e'
		&& name[j][i - 3] == 'b' && name[j][i - 4] == '.' && i > 4)
		return;
	else
		exit (1);
}

void	map_read_line(char *av, x_game *game, int fd)
{
	int		x;

	char *line; 
	x = 0;
	count_line(av, game);
	game->map = malloc(sizeof(char *) * game->wid_line + 1);
	game->map[x] = get_next_line(fd);
	if(!game->map[x])
		return ;
	while(game->map[x])
	{
		x++;
		game->map[x] = get_next_line(fd);
	}
}

void	map_check_len(x_game *game)
{
	int	i;

	i = 0;
	if (!game->map[i])
		exit(1);
	game->len_line = ft_strlen2(game->map[i]);
	while(game->map[i])
	{
		if(ft_strlen2(game->map[i]) != game->len_line)
		{
			ft_printf("len not exixt\n");
			exit (1);
		}
		i++;
	}
}

void	wall_check(x_game *game)
{
	int	x;
	int y;
	int	len;

	x = 1;
	y = 0;
	len = game->len_line;
	while (game->map[0][y])
	{
		if ((game->map[0][y] != '1') && (y < game->len_line))
		{
			ft_printf("first line wall error\n");
			exit (1);
		}
		if (game->map[game->wid_line - 1][y] != '1' 
				&& game->map[game->wid_line - 1][y])
		{
			if (game->map[game->wid_line - 1][y] == '\n')
				return;
			ft_printf("last line wall error\n");
			exit (1);		
		}
		y++;
	}
	while (game->map[x] && x < game->wid_line)
	{
		if (game->map[x][0] != '1' || game->map[x][len - 1] != '1')
		{
			ft_printf("mind line wall error\n");
			exit(1);
		}
		x++;
	}
}

void	join_map(x_game *game)
{
	int		x;
	int		i;
	char	*join_line;

	x = 0;
	i = 0;
	join_line =	ft_calloc(1, 1);
	while(x < game->wid_line)
	{
		join_line = ft_strjoin(join_line, game->map[x]);
		x++;
	}
	game->one_line_map = join_line;
}

void	map_checker_param(x_game *game)
{
	int	i;

	i = 0;
	while (game->one_line_map[i])
	{
		if (game->one_line_map[i] == 'E')
			game->exit++;
		if (game->one_line_map[i] == 'P')
			game->player++;
		if (game->one_line_map[i] == 'C')
			game->coin++;
		i++;
	}
	if (game->exit != 1)
		exit (1);
	if	(game->player != 1)
		exit (1);
	if (game->coin < 1)
		exit (1);
}

void	map_checker_param2(x_game *game)
{
	int	i;
	char *str;

	i = 0;
	str = game->one_line_map;
	while(str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == 'P'
			|| str[i] == 'E' || str[i] == 'C' || str[i] == '\n')
			i++;
		else
		{
			ft_printf("param check faild\n");
			exit (1);
		}
	}
}

void count_line(char *av, x_game *game)
{
	int i;
	int fd1;
	char *line;

	fd1 = open(av, O_RDONLY);
	line = get_next_line(fd1);
	i = 0;
	while(line)
	{
		i++;
		line = get_next_line(fd1);
	}
	game->wid_line = i;
	free(line);
	close(fd1);
}
