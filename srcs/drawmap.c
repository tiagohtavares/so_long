/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:01:27 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/02 22:16:53 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	drawmap(t_data *gameinfo)
{
	int	x;
	int	y;

	load_images(gameinfo);
	y = 0;
	while (gameinfo->map[y])
	{
		x = 0;
		while (gameinfo->map[y][x])
		{
			if (gameinfo->map[y][x] == '1')
				mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
					gameinfo->img_wall, x * 64, y * 64);
			else if (gameinfo->map[y][x] == '0')
				mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
					gameinfo->img_floor, x * 64, y * 64);
			else if (gameinfo->map[y][x] == 'P')
				mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
					gameinfo->img_player, x * 64, y * 64);
			else if (gameinfo->map[y][x] == 'C')
				mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
					gameinfo->img_collect, x * 64, y * 64);
			else if (gameinfo->map[y][x] == 'E')
				mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
					gameinfo->img_exit, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
