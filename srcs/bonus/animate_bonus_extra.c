/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus_extra.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:12:27 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/12 23:16:47 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
#include <time.h>

int	animate_two(t_data *gameinfo)
{
	if (gameinfo->totalframe % 25 == 0)
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
	if (gameinfo->totalframe % 45 == 0)
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
