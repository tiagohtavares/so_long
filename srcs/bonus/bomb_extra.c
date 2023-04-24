/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bomb_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:45:45 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/20 16:03:41 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	destroy_enemy_extra(t_data *gameinfo, int x, int y, int type)
{
	if (type == 2)
	{
		if (gameinfo->map[y][x - 1] == 'Z')
		{
			gameinfo->totalenemy--;
			gameinfo->map[y][x - 1] = '0';
		}
	}
	if (type == 3)
	{
		if (gameinfo->map[y][x + 1] == 'Z')
		{
			gameinfo->totalenemy--;
			gameinfo->map[y][x + 1] = '0';
		}
	}
}

void	destroy_enemy(t_data *gameinfo, int x, int y, int type)
{
	if (gameinfo->map[y][x] == 'Z')
	{
		gameinfo->totalenemy--;
		gameinfo->map[y][x] = '0';
	}
	if (type == 0)
	{
		if (gameinfo->map[y + 1][x] == 'Z')
		{
			gameinfo->totalenemy--;
			gameinfo->map[y + 1][x] = '0';
		}
	}
	if (type == 1)
	{
		if (gameinfo->map[y - 1][x] == 'Z')
		{
			gameinfo->totalenemy--;
			gameinfo->map[y - 1][x] = '0';
		}
	}
	destroy_enemy_extra(gameinfo, x, y, type);
}

int	bomb(t_data *gameinfo)
{
	int		x;
	int		y;

	find_position(gameinfo);
	x = gameinfo->positionx;
	y = gameinfo->positiony;
	if (gameinfo->map[y][x - 1] != '1'
		&& gameinfo->map[y][x - 1] != 'Z'
			&& gameinfo->map[y][x - 1] != 'C'
				&& gameinfo->map[y][x - 1] != 'Z')
	{
		gameinfo->map[y][x - 1] = 'B';
		gameinfo->bomb_on = 1;
	}
	gameinfo->bombx = x - 1;
	gameinfo->bomby = y;
	return (0);
}

void	animate_bomb(t_data *gameinfo)
{
	int	x;
	int	y;

	find_position(gameinfo);
	x = gameinfo->bombx;
	y = gameinfo->bomby;
	if (gameinfo->totalframe % 200 == 0)
	{
		gameinfo->map[y][x] = '0';
		explode(gameinfo);
		gameinfo->bomb_on = 0;
	}
}
