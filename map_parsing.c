/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:50:11 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/18 11:35:26 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_name(char *name)
{
	int i;

	i = ft_strlen(name);
	if (name[i - 1] == 'r' && name[i - 2] == 'e'
		&& name[i - 3] == 'b' && name[i - 4] == '.' && i > 4)
		ft_printf("Work\n");
	else
	{
		ft_printf("Error\n");
		return ;
	}
}

// void	map_check1()
// {

// }