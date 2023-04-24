/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:00:08 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/24 11:59:25 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_e(t_data *gameinfo, int x, int y)
{
		gameinfo->duped_map[y][x] = 'X';
	if (gameinfo->duped_map[y + 1][x] == '0' ||
		gameinfo->duped_map[y + 1][x] == 'C' ||
		gameinfo->duped_map[y + 1][x] == 'E')
		fill_e(gameinfo, x, y + 1);
	if (gameinfo->duped_map[y - 1][x] == '0' ||
		gameinfo->duped_map[y - 1][x] == 'C' ||
		gameinfo->duped_map[y - 1][x] == 'E')
		fill_e(gameinfo, x, y - 1);
	if (gameinfo->duped_map[y][x + 1] == '0' ||
		gameinfo->duped_map[y][x + 1] == 'C' ||
		gameinfo->duped_map[y][x + 1] == 'E')
		fill_e(gameinfo, x + 1, y);
	if (gameinfo->duped_map[y][x - 1] == '0' ||
		gameinfo->duped_map[y][x - 1] == 'C' ||
		gameinfo->duped_map[y][x - 1] == 'E')
		fill_e(gameinfo, x - 1, y);
}

void	fill_c(t_data *gameinfo, int x, int y)
{
	gameinfo->duped_map[y][x] = 'X';
	if (gameinfo->duped_map[y + 1][x] == '0' ||
		gameinfo->duped_map[y + 1][x] == 'C')
		fill_c(gameinfo, x, y + 1);
	if (gameinfo->duped_map[y - 1][x] == '0' ||
		gameinfo->duped_map[y - 1][x] == 'C')
		fill_c(gameinfo, x, y - 1);
	if (gameinfo->duped_map[y][x + 1] == '0' ||
		gameinfo->duped_map[y][x + 1] == 'C')
		fill_c(gameinfo, x + 1, y);
	if (gameinfo->duped_map[y][x - 1] == '0' ||
		gameinfo->duped_map[y][x - 1] == 'C')
		fill_c(gameinfo, x - 1, y);
}

void	check_coins_left(t_data *gameinfo)
{
	int	x;
	int	y;
	int	c;

	y = 0;
	c = 0;
	while (gameinfo->duped_map[y])
	{
		x = 0;
		while (gameinfo->duped_map[y][x])
		{
			if (gameinfo->duped_map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	if (c > 0)
	{
		clear_duped(gameinfo);
		error(2, gameinfo);
	}
}

void	check_exit(t_data *gameinfo)
{
	int	x;
	int	y;
	int	c;

	y = 0;
	c = 0;
	while (gameinfo->duped_map[y])
	{
		x = 0;
		while (gameinfo->duped_map[y][x])
		{
			if (gameinfo->duped_map[y][x] == 'E')
				c++;
			x++;
		}
		y++;
	}
	if (c != 0)
	{
		clear_duped(gameinfo);
		error(2, gameinfo);
	}
}

void	flood_fill(t_data *gameinfo)
{
	int	x;
	int	y;

	gameinfo->duped_positionx = 0;
	gameinfo->duped_positiony = 0;
	dupe_map(gameinfo);
	find_position_duped(gameinfo);
	x = gameinfo->duped_positionx;
	y = gameinfo->duped_positiony;
	fill_c(gameinfo, x, y);
	check_coins_left(gameinfo);
	clear_duped(gameinfo);
	dupe_map(gameinfo);
	find_position_duped(gameinfo);
	x = gameinfo->duped_positionx;
	y = gameinfo->duped_positiony;
	fill_e(gameinfo, x, y);
	check_exit(gameinfo);
	clear_duped(gameinfo);
}
