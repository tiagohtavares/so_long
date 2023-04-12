/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:09:26 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/12 15:09:41 by ttavares         ###   ########.fr       */
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
