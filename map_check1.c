/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:50:11 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/30 02:11:22 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32 || str[i] == '\t')
			return (0);
		i++;
	}
	return (1);
}

int	check_name(char *av1)
{
	int		i;
	int		j;
	char	**name;

	if (check_space(av1) == 0)
		return (0);
	j = ft_count_word(av1, '/') - 1;
	name = ft_split(av1, '/');
	i = ft_strlen(name[j]);
	if (name[j][i - 1] == 'r' && name[j][i - 2] == 'e'
		&& name[j][i - 3] == 'b' && name[j][i - 4] == '.' && i > 4)
	{
		free_double_pointer(name);
		return (1);
	}
	else
	{
		write(1, "Name no valid :(\n", 17);
		free_double_pointer(name);
		return (0);
	}
	free_double_pointer(name);
	return (1);
}

int	map_read_line(char *av, x_game *game, int fd)
{
	int	x;

	x = 0;
	count_line(av, game);
	game->map = malloc(sizeof(char *) * game->wid_line + 1);
	if (!game->map)
		return (0);
	game->map[x] = get_next_line(fd);
	if (!game->map[x])
		return (0);
	while (game->map[x])
	{
		x++;
		game->map[x] = get_next_line(fd);
	}
	return (1);
}

int	map_check_len(x_game *game)
{
	int	i;

	i = 0;
	if (!game->map[i])
		return (0);
	game->len_line = ft_strlen2(game->map[i]);
	while (game->map[i])
	{
		if (ft_strlen2(game->map[i]) != game->len_line)
		{
			write(1, "Map is not Rectangular\n", 23);
			return (0);
		}
		i++;
	}
	return (1);
}

int	join_map(x_game *game)
{
	int		x;
	int		i;
	char	*join_line;

	x = 0;
	i = 0;
	join_line = malloc(1);
	if (!join_line)
		return (0);
	join_line[0] = '\0';
	while (x < game->wid_line)
	{
		join_line = ft_strjoin(join_line, game->map[x]);
		x++;
	}
	game->one_line_map = ft_strdup(join_line);
	free(join_line);
	return (1);
}
