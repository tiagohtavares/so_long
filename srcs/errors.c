/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:22:30 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/10 20:14:41 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_clean(t_data *gameinfo)
{
	mlx_destroy_image(gameinfo->mlx, gameinfo->img_collect);
	mlx_destroy_image(gameinfo->mlx, gameinfo->img_exit);
	mlx_destroy_image(gameinfo->mlx, gameinfo->img_floor);
	mlx_destroy_image(gameinfo->mlx, gameinfo->img_player);
	mlx_destroy_image(gameinfo->mlx, gameinfo->img_wall);
	mlx_destroy_window(gameinfo->mlx, gameinfo->mlx_window);
	mlx_destroy_display(gameinfo->mlx);
	free(gameinfo->mlx);
	clearmap(gameinfo);
	exit(0);
	return (0);
}

void	error(int type, t_data *gameinfo)
{
	if (type == 0)
	{
		ft_printf("Error\n");
		ft_printf("Error reading the map\n");
		exit(0);
	}
	else if (type == 1)
	{
		exit_clean(gameinfo);
	}
	else if (type == 2)
	{
		clearmap(gameinfo);
		ft_printf("Error\n");
		ft_printf("Error in map configuration.\n");
		exit(0);
	}
}
