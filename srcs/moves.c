/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:28:01 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/09 09:13:05 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	update_position(t_data *gameinfo, char type)
{
	int		x;
	int		y;
	char	swap;

	x = gameinfo->positionx;
	y = gameinfo->positiony;
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
	else if (type == 'a' && gameinfo->map[y][x - 1] != '1')
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

int	move_isvalid(t_data *gameinfo, char type)
{
	int		x;
	int		y;

	x = gameinfo->positionx;
	y = gameinfo->positiony;
	if (type == 'w' && gameinfo->map[y - 1][x] != '1')
	{
		if (gameinfo->map[y - 1][x] == 'C')
		{
			gameinfo->map[y - 1][x] = '0';
			gameinfo->collected++;
		}
		if (gameinfo->map[y - 1][x] == 'E' && gameinfo->collected == gameinfo->totalcollectables)
			error(1, gameinfo);
		if ((gameinfo->map[y - 1][x] == 'E' && gameinfo->collected != gameinfo->totalcollectables))
			return (0);
		return (1);
	}
	else if (type == 's' && gameinfo->map[y + 1][x] != '1')
	{
		if (gameinfo->map[y + 1][x] == 'C')
		{
			gameinfo->map[y + 1][x] = '0';
			gameinfo->collected++;
		}
		if (gameinfo->map[y + 1][x] == 'E' && gameinfo->collected == gameinfo->totalcollectables)
			error(1, gameinfo);
		if ((gameinfo->map[y + 1][x] == 'E' && gameinfo->collected != gameinfo->totalcollectables))
			return (0);
		return (1);
	}
	else if (type == 'a' && gameinfo->map[y][x - 1] != '1')
	{
		if (gameinfo->map[y][x - 1] == 'C')
		{
			gameinfo->map[y][x - 1] = '0';
			gameinfo->collected++;
		}
		if (gameinfo->map[y][x - 1] == 'E' && gameinfo->collected == gameinfo->totalcollectables)
			error(1, gameinfo);
		if ((gameinfo->map[y][x - 1] == 'E' && gameinfo->collected != gameinfo->totalcollectables))
			return (0);
		return (1);
	}
	else if (type == 'd' && gameinfo->map[y][x + 1] != '1')
	{
		if (gameinfo->map[y][x + 1] == 'C')
		{
			gameinfo->map[y][x + 1] = '0';
			gameinfo->collected++;
		}
		if (gameinfo->map[y][x + 1] == 'E' && gameinfo->collected == gameinfo->totalcollectables)
			error(1, gameinfo);
		if ((gameinfo->map[y][x + 1] == 'E' && gameinfo->collected != gameinfo->totalcollectables))
			return (0);
		return (1);
	}
	return (0);
}

void	moves(int key, t_data *gameinfo)
{
	if (key == XK_w)
	{
		find_position(gameinfo);
		if (move_isvalid(gameinfo, 'w') == 1)
		{
			mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
				gameinfo->img_floor, gameinfo->positionx * 64,
				gameinfo->positiony * 64);
			mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
				gameinfo->img_player, gameinfo->positionx * 64,
				(gameinfo->positiony - 1) * 64);
			update_position(gameinfo, 'w');
			gameinfo->moves++;
			ft_printf("Moves: %d\n", gameinfo->moves);
		}
	}
	else if (key == XK_s)
	{
		find_position(gameinfo);
		if (move_isvalid(gameinfo, 's') == 1)
		{
			mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
				gameinfo->img_floor, gameinfo->positionx * 64,
				gameinfo->positiony * 64);
			mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
				gameinfo->img_player, gameinfo->positionx * 64,
				(gameinfo->positiony + 1) * 64);
			update_position(gameinfo, 's');
			gameinfo->moves++;
			ft_printf("Moves: %d\n", gameinfo->moves);
		}
	}
	else if (key == XK_a)
	{
		find_position(gameinfo);
		if (move_isvalid(gameinfo, 'a') == 1)
		{
			mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
				gameinfo->img_floor, gameinfo->positionx * 64,
				gameinfo->positiony * 64);
			mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
				gameinfo->img_player, (gameinfo->positionx - 1) * 64,
				gameinfo->positiony * 64);
			update_position(gameinfo, 'a');
			gameinfo->moves++;
			ft_printf("Moves: %d\n", gameinfo->moves);
		}
	}
	else if (key == XK_d)
	{
		find_position(gameinfo);
		if (move_isvalid(gameinfo, 'd') == 1)
		{
			mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
				gameinfo->img_floor, gameinfo->positionx * 64,
				gameinfo->positiony * 64);
			mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
				gameinfo->img_player, (gameinfo->positionx + 1) * 64,
				gameinfo->positiony * 64);
			update_position(gameinfo, 'd');
			gameinfo->moves++;
			ft_printf("Moves: %d\n", gameinfo->moves);
		}
	}
}
