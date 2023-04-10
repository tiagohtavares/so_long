/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:28:01 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/11 00:01:22 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	move_w(t_data *gameinfo)
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
		drawmap(gameinfo);
	}
}

void	move_s(t_data *gameinfo)
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
		drawmap(gameinfo);
	}
}

void	move_a(t_data *gameinfo)
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
		drawmap(gameinfo);
	}
}

void	move_d(t_data *gameinfo)
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
		drawmap(gameinfo);
	}
}

void	moves(int key, t_data *gameinfo)
{
	if (key == XK_w)
		move_w(gameinfo);
	else if (key == XK_s)
		move_s(gameinfo);
	else if (key == XK_a)
		move_a(gameinfo);
	else if (key == XK_d)
		move_d(gameinfo);
}
