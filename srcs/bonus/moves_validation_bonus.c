/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_validation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:57:50 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/20 15:44:02 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	moves_w(t_data *gameinfo, int x, int y)
{
	if (gameinfo->map[y - 1][x] == 'C')
	{
		gameinfo->map[y - 1][x] = '0';
		gameinfo->collected++;
	}
	if (gameinfo->map[y - 1][x] == 'E'
		&& gameinfo->collected == gameinfo->totalcollectables)
		error(1, gameinfo);
	if (gameinfo->map[y - 1][x] == 'Z')
		error(1, gameinfo);
	if ((gameinfo->map[y - 1][x] == 'E'
		&& gameinfo->collected != gameinfo->totalcollectables))
		return (0);
	return (1);
}

int	moves_s(t_data *gameinfo, int x, int y)
{
	if (gameinfo->map[y + 1][x] == 'C')
	{
		gameinfo->map[y + 1][x] = '0';
		gameinfo->collected++;
	}
	if (gameinfo->map[y + 1][x] == 'E'
		&& gameinfo->collected == gameinfo->totalcollectables)
		error(1, gameinfo);
	if (gameinfo->map[y + 1][x] == 'Z')
		error(1, gameinfo);
	if ((gameinfo->map[y + 1][x] == 'E'
		&& gameinfo->collected != gameinfo->totalcollectables))
		return (0);
	return (1);
}

int	moves_a(t_data *gameinfo, int x, int y)
{
	if (gameinfo->map[y][x - 1] == 'C')
	{
		gameinfo->map[y][x - 1] = '0';
		gameinfo->collected++;
	}
	if (gameinfo->map[y][x - 1] == 'E'
		&& gameinfo->collected == gameinfo->totalcollectables)
		error(1, gameinfo);
	if (gameinfo->map[y][x - 1] == 'Z')
		error(1, gameinfo);
	if ((gameinfo->map[y][x - 1] == 'E'
		&& gameinfo->collected != gameinfo->totalcollectables))
		return (0);
	return (1);
}

int	moves_d(t_data *gameinfo, int x, int y)
{
	if (gameinfo->map[y][x + 1] == 'C')
	{
		gameinfo->map[y][x + 1] = '0';
		gameinfo->collected++;
	}
	if (gameinfo->map[y][x + 1] == 'E'
		&& gameinfo->collected == gameinfo->totalcollectables)
		error(1, gameinfo);
	if (gameinfo->map[y][x + 1] == 'Z')
		error(1, gameinfo);
	if ((gameinfo->map[y][x + 1] == 'E'
		&& gameinfo->collected != gameinfo->totalcollectables))
		return (0);
	return (1);
}

int	move_isvalid(t_data *gameinfo, char type)
{
	int		x;
	int		y;
	int		r;

	x = gameinfo->positionx;
	y = gameinfo->positiony;
	r = 0;
	if (type == 'w' && gameinfo->map[y - 1][x] != '1'
		&& gameinfo->map[y - 1][x] != 'F'
			&& gameinfo->map[y - 1][x] != 'B')
		r = moves_w(gameinfo, x, y);
	else if (type == 's' && gameinfo->map[y + 1][x] != '1'
		&& gameinfo->map[y + 1][x] != 'F'
			&& gameinfo->map[y + 1][x] != 'B')
		r = moves_s(gameinfo, x, y);
	else if (type == 'a' && gameinfo->map[y][x - 1] != '1'
		&& gameinfo->map[y][x - 1] != 'F'
			&& gameinfo->map[y][x - 1] != 'B')
		r = moves_a(gameinfo, x, y);
	else if (type == 'd' && gameinfo->map[y][x + 1] != '1'
		&& gameinfo->map[y][x + 1] != 'F'
			&& gameinfo->map[y][x + 1] != 'B')
		r = moves_d(gameinfo, x, y);
	return (r);
}
