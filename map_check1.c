/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:50:11 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/22 00:49:29 by mozahnou         ###   ########.fr       */
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
		ft_printf("Work\n");
	else
	{
		ft_printf("Error\n");
		exit (1);
	}
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

void	wall_check(x_game *game)
{
	int	x;
	int y;

	x = 1;
	y = 0;
	while (game->map[1][y])
	{
		if (game->map[0][y] != '1' || game->map[0][y] != '\n')
		{
			printf("%c", game->map[0][y]);
			ft_printf("Wall check failed\n");
			exit (1);
		}
		y++;
	}
	// pause();
}

void	map_check_len(x_game *game)
{
	int	i;

	i = 0;
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


void	map_checker(x_game *game)
{
	int		i;
	char	*join_line;

	i = 0;
	join_line =	ft_calloc(1, 1);
	while(i < game->wid_line)
	{
		join_line = ft_strjoin(join_line, game->map[i]);
		i++;
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
