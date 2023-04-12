/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:28:01 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/12 16:27:19 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	move_w(t_data *gameinfo)
{
	find_position(gameinfo);
	if (move_isvalid(gameinfo, 'w') == 1)
	{
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
