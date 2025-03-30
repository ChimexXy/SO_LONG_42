/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:48:30 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/30 01:47:53 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
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

