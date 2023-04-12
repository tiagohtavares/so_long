/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:43:48 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/12 23:16:37 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
#include <time.h>

int	find_positiony(t_data *gameinfo)
{
	int	y;
	int	x;

	y = 0;
	while (gameinfo->map[y])
	{
		x = 0;
		while (gameinfo->map[y][x])
		{
			if (gameinfo->map[y][x] == 'Z')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int	find_positionx(t_data *gameinfo)
{
	int	y;
	int	x;

	y = 0;
	while (gameinfo->map[y])
	{
		x = 0;
		while (gameinfo->map[y][x])
		{
			if (gameinfo->map[y][x] == 'Z')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

void	move_enemy_side(t_data *gameinfo, int x, int y, clock_t now)
{
	char	swap;

	if (gameinfo->map[y][x - 1] == 'P')
		error(1, gameinfo);
	if (gameinfo->map[y][x - 1] != '1' &&
		gameinfo->map[y][x - 1] != 'E' &&
		gameinfo->map[y][x - 1] != 'C' && (now % 2 == 0))
	{
		swap = gameinfo->map[y][x];
		gameinfo->map[y][x] = gameinfo->map[y][x - 1];
		gameinfo->map[y][x - 1] = swap;
	}
	if (gameinfo->map[y][x + 1] == 'P')
		error(1, gameinfo);
	if (gameinfo->map[y][x + 1] != '1' &&
		gameinfo->map[y][x + 1] != 'P' &&
		gameinfo->map[y][x + 1] != 'E' &&
		gameinfo->map[y][x + 1] != 'C' && (now % 3 == 0))
	{
		swap = gameinfo->map[y][x];
		gameinfo->map[y][x] = gameinfo->map[y][x + 1];
		gameinfo->map[y][x + 1] = swap;
	}
}

void	move_enemy_top(t_data *gameinfo, int x, int y, clock_t now)
{
	char	swap;

	if (gameinfo->map[y + 1][x] == 'P')
		error(1, gameinfo);
	if (gameinfo->map[y + 1][x] != '1' &&
		gameinfo->map[y + 1][x] != 'P' &&
		gameinfo->map[y + 1][x] != 'E' &&
		gameinfo->map[y + 1][x] != 'C' && (now % 2 == 0))
	{
		swap = gameinfo->map[y][x];
		gameinfo->map[y][x] = gameinfo->map[y + 1][x];
		gameinfo->map[y + 1][x] = swap;
	}
	if (gameinfo->map[y - 1][x] == 'P')
		error(1, gameinfo);
	if (gameinfo->map[y - 1][x] != '1' &&
		gameinfo->map[y - 1][x] != 'P' &&
		gameinfo->map[y - 1][x] != 'E' &&
		gameinfo->map[y - 1][x] != 'C' && (now % 3 == 0))
	{
		swap = gameinfo->map[y][x];
		gameinfo->map[y][x] = gameinfo->map[y - 1][x];
		gameinfo->map[y - 1][x] = swap;
	}
}

int	animate(t_data *gameinfo)
{
	int			x;
	int			y;

	x = find_positionx(gameinfo);
	y = find_positiony(gameinfo);
	animate_one(gameinfo);
	animate_two(gameinfo);
	if (gameinfo->totalframe % 30 == 0)
	{
		if (rand() % 2 == 0)
			move_enemy_side(gameinfo, x, y, rand());
		if (rand() % 3 == 0)
			move_enemy_top(gameinfo, x, y, rand());
	}
	gameinfo->frame = 0;
	return (0);
}
