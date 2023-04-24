/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus_extra.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:12:27 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/24 12:16:02 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
#include <time.h>

void	delay(t_data *gameinfo)
{
	gameinfo->frame = 0;
	while (gameinfo->frame < 2000000)
	{
		gameinfo->frame++;
	}
}

int	animate_two(t_data *gameinfo)
{
	if (gameinfo->totalframe % 30 == 0)
	{
		mlx_destroy_image(gameinfo->mlx, gameinfo->img_enemy1);
		gameinfo->img_enemy1 = mlx_xpm_file_to_image
			(gameinfo->mlx, "assets/sprites/slime2.xpm",
				gameinfo->imagex, gameinfo->imagey);
		mlx_destroy_image(gameinfo->mlx, gameinfo->img_player);
		gameinfo->img_player = mlx_xpm_file_to_image
			(gameinfo->mlx, "assets/sprites/player2.xpm",
				gameinfo->imagex, gameinfo->imagey);
	}
	if (gameinfo->totalframe % 50 == 0)
	{
		mlx_destroy_image(gameinfo->mlx, gameinfo->img_player);
		gameinfo->img_player = mlx_xpm_file_to_image
			(gameinfo->mlx, "assets/sprites/player4.xpm",
				gameinfo->imagex, gameinfo->imagey);
	}
	return (0);
}

int	animate_one(t_data *gameinfo)
{
	if (gameinfo->totalframe % 10 == 0)
	{
		mlx_destroy_image(gameinfo->mlx, gameinfo->img_enemy1);
		gameinfo->img_enemy1 = mlx_xpm_file_to_image
			(gameinfo->mlx, "assets/sprites/slime1.xpm",
				gameinfo->imagex, gameinfo->imagey);
		mlx_destroy_image(gameinfo->mlx, gameinfo->img_player);
		gameinfo->img_player = mlx_xpm_file_to_image
			(gameinfo->mlx, "assets/sprites/player1.xpm",
				gameinfo->imagex, gameinfo->imagey);
	}
	return (0);
}

void	animate_enemy(t_data *gameinfo, int x, int y)
{
	if (gameinfo->totalframe % 150 == 0 && gameinfo->totalenemy > 0)
	{
		if (rand() % 3 == 0)
			move_enemy_side(gameinfo, x, y, rand());
		if (rand() % 2 == 0)
			move_enemy_top(gameinfo, x, y, rand());
	}
}

void	clear_fire(t_data *gameinfo)
{
	int	y;
	int	x;

	y = 0;
	while (gameinfo->map[y])
	{
		x = 0;
		while (gameinfo->map[y][x])
		{
			if (gameinfo->map[y][x] == 'F')
				gameinfo->map[y][x] = '0';
			x++;
		}
		y++;
	}
}
