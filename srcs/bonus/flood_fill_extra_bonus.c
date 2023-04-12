/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_extra_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:11:11 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/12 16:10:25 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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

void	clear_exit(t_data *gameinfo)
{
	clear_duped(gameinfo);
	error(2, gameinfo);
}
