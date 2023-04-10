/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:44:52 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/10 19:45:14 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_empty(t_data *gameinfo)
{
	int	x;
	int	y;

	y = 0;
	while (gameinfo->map[y])
	{
		x = 0;
		while (gameinfo->map[y][x])
		{
			if (gameinfo->map[y][x] != 'P' && gameinfo->map[y][x] != 'E' &&
				gameinfo->map[y][x] != '0' && gameinfo->map[y][x] != 'C' &&
				gameinfo->map[y][x] != '1')
				error(2, gameinfo);
			x++;
		}
		y++;
	}
}

void	check_rectangle(t_data *gameinfo)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	j = 0;
	while (gameinfo->map[y])
	{
		x = 0;
		i = 0;
		while (gameinfo->map[y][x])
		{
			i++;
			x++;
		}
		if (i != gameinfo->windowx)
			error(2, gameinfo);
		j++;
		y++;
	}
	if (j != gameinfo->windowy)
		error(2, gameinfo);
}
