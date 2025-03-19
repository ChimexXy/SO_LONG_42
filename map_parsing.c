/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:50:11 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/19 14:52:07 by mozahnou         ###   ########.fr       */
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

	if (check_space(av1) == 0)
		return ;
	j = ft_count_word(av1) - 1;
	name = ft_split(av1);
	i = ft_strlen(name[j]);
	if (name[j][i - 1] == 'r' && name[j][i - 2] == 'e'
		&& name[j][i - 3] == 'b' && name[j][i - 4] == '.' && i > 4)
		ft_printf("Work\n");
	else
	{
		ft_printf("Error\n");
		return ;
	}
}

void	map_check1(x_game game, int fd)
{
	int	x;

	x = 0;
	game.map[x] = get_next_line(fd);
	while(game.map[x])
	{
		printf("%s", game.map[x]);
		x++;
		game.map = get_next_line(fd);
	}
}

int main()
{
	x_game game;
	int fd = open("t.txt", O_RDONLY);
	map_check1(game, fd);
}