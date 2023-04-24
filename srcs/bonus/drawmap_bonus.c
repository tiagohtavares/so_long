/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:01:27 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/18 16:22:03 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	drawmap_extra(t_data *gameinfo, int y, int x)
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
}

void	drawmap_enemy(t_data *gameinfo, int y, int x)
{
	char	*temp;

	temp = ft_itoa(gameinfo->moves);
	if (gameinfo->map[y][x] == 'Z')
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_enemy1, x * 64, y * 64);
	if (gameinfo->map[y][x] == 'B' && gameinfo->bomb_on == 1)
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_bomb, x * 64, y * 64);
	if (gameinfo->map[y][x] == 'F')
		mlx_put_image_to_window(gameinfo->mlx, gameinfo->mlx_window,
			gameinfo->img_fire, x * 64, y * 64);
	mlx_string_put(gameinfo->mlx, gameinfo->mlx_window, 32, 32,
		0xFFFFFF, "Moves :");
	mlx_string_put(gameinfo->mlx, gameinfo->mlx_window, 78, 32,
		0xFFFFFF, temp);
	free(temp);
}

int	drawmap(t_data *gameinfo)
{
	int	x;
	int	y;

	gameinfo->totalframe++;
	if (gameinfo->totalframe % 60)
	{
		y = 0;
		while (gameinfo->map[y])
		{
			x = 0;
			while (gameinfo->map[y][x])
			{
				drawmap_extra(gameinfo, y, x);
				drawmap_enemy(gameinfo, y, x);
				x++;
			}
			y++;
		}
	}
	animate(gameinfo);
	return (0);
}
