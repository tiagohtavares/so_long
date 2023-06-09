/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_extra_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:52:39 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/18 14:53:27 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	swap_top(t_data *gameinfo, int y, int x, char type)
{
	char	swap;

	if (type == 'w' && gameinfo->map[y - 1][x] != '1')
	{
		swap = gameinfo->map[y][x];
		gameinfo->map[y][x] = gameinfo->map[y - 1][x];
		gameinfo->map[y - 1][x] = swap;
	}
	else if (type == 's' && gameinfo->map[y + 1][x] != '1')
	{
		swap = gameinfo->map[y][x];
		gameinfo->map[y][x] = gameinfo->map[y + 1][x];
		gameinfo->map[y + 1][x] = swap;
	}
}

void	update_position(t_data *gameinfo, char type)
{
	int		x;
	int		y;
	char	swap;

	x = gameinfo->positionx;
	y = gameinfo->positiony;
	swap_top(gameinfo, y, x, type);
	if (type == 'a' && gameinfo->map[y][x - 1] != '1')
	{
		swap = gameinfo->map[y][x];
		gameinfo->map[y][x] = gameinfo->map[y][x - 1];
		gameinfo->map[y][x - 1] = swap;
	}
	else if (type == 'd' && gameinfo->map[y][x + 1] != '1')
	{
		swap = gameinfo->map[y][x];
		gameinfo->map[y][x] = gameinfo->map[y][x + 1];
		gameinfo->map[y][x + 1] = swap;
	}
}

void	find_position(t_data *gameinfo)
{
	int	y;
	int	x;

	y = 0;
	while (gameinfo->map[y])
	{
		x = 0;
		while (gameinfo->map[y][x])
		{
			if (gameinfo->map[y][x] == 'P')
			{
				gameinfo->positionx = x;
				gameinfo->positiony = y;
			}
			x++;
		}
		y++;
	}
}
