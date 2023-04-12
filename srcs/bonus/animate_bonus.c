/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:43:48 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/12 16:18:30 by ttavares         ###   ########.fr       */
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
	drawmap(gameinfo);
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
	drawmap(gameinfo);
}

int	animate(t_data *gameinfo)
{
	int			x;
	int			y;

	x = find_positionx(gameinfo);
	y = find_positiony(gameinfo);
	while (gameinfo->frame < 20000000)
		gameinfo->frame++;
	if (gameinfo->totalframe % 10 == 0)
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_enemy1, x * 64, y * 64);
	if (gameinfo->totalframe % 25 == 0)
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_enemy2, x * 64, y * 64);
	gameinfo->frame = 0;
	gameinfo->totalframe++;
	if (gameinfo->totalframe % 30 == 0)
	{
		if (rand() % 2 == 0)
			move_enemy_side(gameinfo, x, y, rand());
		if (rand() % 3 == 0)
			move_enemy_top(gameinfo, x, y, rand());
	}
	return (0);
}
