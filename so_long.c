/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 06:33:25 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/19 21:14:32 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	int	fd;
	x_game game;

	if (ac != 2)
		ft_printf("Error number of arguments is not enought\n");
	check_name(av[1]);
	fd = open(av[1], O_RDONLY);
	map_check1(game, fd);
}