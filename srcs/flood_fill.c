/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:00:08 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/10 01:35:51 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_position_duped(t_data *gameinfo)
{
	int	y;
	int	x;

	y = 0;
	while (gameinfo->duped_map[y])
	{
		x = 0;
		while (gameinfo->duped_map[y][x])
		{
			if (gameinfo->duped_map[y][x] == 'P')
			{
				gameinfo->duped_positionx = x;
				gameinfo->duped_positiony = y;
			}
			x++;
		}
		y++;
	}
}

void	fill(t_data *gameinfo, int x, int y)
{
	gameinfo->duped_map[y][x] = 'X';
	if (gameinfo->duped_map[y + 1][x] == '0' ||
		gameinfo->duped_map[y + 1][x] == 'C' ||
		gameinfo->duped_map[y + 1][x] == 'E')
		fill(gameinfo, x, y + 1);
	if (gameinfo->duped_map[y - 1][x] == '0' ||
		gameinfo->duped_map[y - 1][x] == 'C' ||
		gameinfo->duped_map[y + 1][x] == 'E')
		fill(gameinfo, x, y - 1);
	if (gameinfo->duped_map[y][x + 1] == '0' ||
		gameinfo->duped_map[y][x + 1] == 'C' ||
		gameinfo->duped_map[y + 1][x] == 'E')
		fill(gameinfo, x + 1, y);
	if (gameinfo->duped_map[y][x - 1] == '0' ||
		gameinfo->duped_map[y][x - 1] == 'C' ||
		gameinfo->duped_map[y + 1][x] == 'E')
		fill(gameinfo, x - 1, y);
}

void	check_coins_left(t_data *gameinfo)
{
	int	x;
	int	y;
	int	c;
	int	e;

	y = 0;
	c = 0;
	e = 0;
	while (gameinfo->duped_map[y])
	{
		x = 0;
		while (gameinfo->duped_map[y][x])
		{
			if (gameinfo->duped_map[y][x] == 'C')
				c++;
			if (gameinfo->duped_map[y][x] == 'E')
				e++;
			x++;
		}
		y++;
	}
	if (c > 0 || e > 0)
		error(2, gameinfo);
}

void	flood_fill(t_data *gameinfo)
{
	int	x;
	int	y;

	gameinfo->duped_positionx = 0;
	gameinfo->duped_positiony = 0;
	find_position_duped(gameinfo);
	x = gameinfo->duped_positionx;
	y = gameinfo->duped_positiony;
	fill(gameinfo, x, y);
	check_coins_left(gameinfo);
}
