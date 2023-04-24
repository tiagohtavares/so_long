/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bomb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:52:08 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/20 16:48:42 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	fire_extra(t_data *gameinfo, int x, int y)
{
	if (gameinfo->map[y + 1][x] != '1'
		&& gameinfo->map[y + 1][x] != 'P'
			&& gameinfo->map[y + 1][x] != 'E'
				&& gameinfo->map[y + 1][x] != 'C')
		gameinfo->map[y + 1][x] = 'F';
	if (gameinfo->map[y - 1][x] != '1'
		&& gameinfo->map[y - 1][x] != 'P'
			&& gameinfo->map[y - 1][x] != 'E'
				&& gameinfo->map[y - 1][x] != 'C')
		gameinfo->map[y - 1][x] = 'F';
	if (gameinfo->map[y][x - 1] != '1'
		&& gameinfo->map[y][x - 1] != 'P'
			&& gameinfo->map[y][x - 1] != 'E'
				&& gameinfo->map[y][x - 1] != 'C')
		gameinfo->map[y][x - 1] = 'F';
	if (gameinfo->map[y][x + 1] != '1'
		&& gameinfo->map[y][x + 1] != 'P'
			&& gameinfo->map[y][x + 1] != 'E'
				&& gameinfo->map[y][x + 1] != 'C')
		gameinfo->map[y][x + 1] = 'F';
}

void	fire_extra_two(t_data *gameinfo, int s, int x, int y)
{
	if (s == 2)
	{
		if (gameinfo->map[y][x - 1] == '0')
			gameinfo->map[y][x - 1] = 'F';
		if (gameinfo->map[y][x - 2] == '0')
			gameinfo->map[y][x - 2] = 'F';
	}
	if (s == 3)
	{
		if (gameinfo->map[y][x + 1] == '0')
			gameinfo->map[y][x + 1] = 'F';
		if (gameinfo->map[y][x + 2] == '0')
			gameinfo->map[y][x + 2] = 'F';
	}
}

void	fire(t_data *gameinfo, int s)
{
	int	x;
	int	y;

	x = gameinfo->bombx;
	y = gameinfo->bomby;
	fire_extra(gameinfo, x, y);
	if (s == 0)
	{
		if (gameinfo->map[y + 1][x] == '0')
			gameinfo->map[y + 1][x] = 'F';
		if (gameinfo->map[y + 2][x] == '0')
			gameinfo->map[y + 2][x] = 'F';
	}
	if (s == 1)
	{
		if (gameinfo->map[y - 1][x] == '0')
			gameinfo->map[y - 1][x] = 'F';
		if (gameinfo->map[y - 2][x] == '0')
			gameinfo->map[y - 2][x] = 'F';
	}
	fire_extra_two(gameinfo, s, x, y);
}

void	explode_extra(t_data *gameinfo, int x, int y)
{
	if (x + 2 < gameinfo->windowx)
	{
		if (gameinfo->map[y][x + 1] == 'Z' || gameinfo->map[y][x + 2] == 'Z')
			destroy_enemy(gameinfo, x + 1, y, 3);
		fire(gameinfo, 3);
	}
	if (x - 2 > 0)
	{
		if (gameinfo->map[y][x - 1] == 'Z' || gameinfo->map[y][x - 2] == 'Z')
			destroy_enemy(gameinfo, x - 1, y, 2);
		fire(gameinfo, 2);
	}
}

void	explode(t_data *gameinfo)
{
	int	x;
	int	y;

	x = gameinfo->bombx;
	y = gameinfo->bomby;
	if ((y + 2) < gameinfo->windowy)
	{
		if (gameinfo->map[y + 1][x] == 'Z' || gameinfo->map[y + 2][x] == 'Z')
			destroy_enemy(gameinfo, x, y + 1, 0);
		fire(gameinfo, 0);
	}
	if (y - 2 > 0)
	{
		if (gameinfo->map[y - 1][x] == 'Z' || gameinfo->map[y - 2][x] == 'Z')
			destroy_enemy(gameinfo, x, y - 1, 1);
		fire(gameinfo, 1);
	}
	explode_extra(gameinfo, x, y);
	gameinfo->bomb_on = 0;
}
