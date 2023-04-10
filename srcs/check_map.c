/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:36:44 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/10 01:45:47 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_player_count(t_data *gameinfo)
{
	int	x;
	int	y;
	int	playercount;

	playercount = 0;
	y = 0;
	while (gameinfo->map[y])
	{
		x = 0;
		while (gameinfo->map[y][x])
		{
			if (gameinfo->map[y][x] == 'P')
				playercount++;
			x++;
		}
		y++;
	}
	if (playercount != 1)
		error(2, gameinfo);
}

void	check_exit_count(t_data *gameinfo)
{
	int	x;
	int	y;
	int	exitcount;

	exitcount = 0;
	y = 0;
	while (gameinfo->map[y])
	{
		x = 0;
		while (gameinfo->map[y][x])
		{
			if (gameinfo->map[y][x] == 'E')
				exitcount++;
			x++;
		}
		y++;
	}
	if (exitcount != 1)
		error(2, gameinfo);
}

void	check_surrounded_walls(t_data *gameinfo)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (gameinfo->map[0][x] == '1' &&
		gameinfo->map[gameinfo->windowy - 1][x] == '1')
		x++;
	if (x != gameinfo->windowx)
		error(2, gameinfo);
	while (gameinfo->map[y])
	{
		if (gameinfo->map[y][0] == '1' &&
			gameinfo->map[y][gameinfo->windowx - 1] == '1')
			i++;
		y++;
	}
	if (i != gameinfo->windowy)
		error(2, gameinfo);

}

void	check_coins_count(t_data *gameinfo)
{
	int	x;
	int	y;

	gameinfo->totalcollectables = 0;
	y = 0;
	while (gameinfo->map[y])
	{
		x = 0;
		while (gameinfo->map[y][x])
		{
			if (gameinfo->map[y][x] == 'C')
				gameinfo->totalcollectables++;
			x++;
		}
		y++;
	}
	if (gameinfo->totalcollectables == 0)
		error(2, gameinfo);
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

void	check_map(t_data *gameinfo)
{
	if (gameinfo->emptyline == 1)
		error(2, gameinfo);
	check_empty(gameinfo);
	check_rectangle(gameinfo);
	check_surrounded_walls(gameinfo);
	check_player_count(gameinfo);
	check_exit_count(gameinfo);
	check_coins_count(gameinfo);
	check_path(gameinfo);
}
