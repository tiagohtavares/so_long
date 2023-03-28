/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:27:02 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/28 17:14:13 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_line(s_data *mlx, int x, int y, int colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			mlx_pixel_put(mlx->mlx, mlx->mlx_window, x + i, y + j, colour);
			j++;
		}
		i++;
	}
	return ;
}


int	moveup(int	key, s_data *p)
{
	if (key == XK_Escape)
		exit(0);
	else if (key == XK_d)
	{
		if (p->offsetx <= 512)
			p->offsetx += 64;
		draw_line(p, 0 + p->offsetx - 64, 0 + p->offsety, 0x000000);
		mlx_put_image_to_window(p->mlx, p->mlx_window, p->image, 0 + p->offsetx, 0 + p->offsety);
		return (0);
	}
	else if (key == XK_a)
	{
		if (p->offsetx >= 64)
			p->offsetx -= 64;
		draw_line(p, 0 + p->offsetx + 64, 0 + p->offsety, 0x000000);
		mlx_put_image_to_window(p->mlx, p->mlx_window, p->image, 0 + p->offsetx, 0 + p->offsety);
		return (0);
	}
	else if (key == XK_s)
	{
		if (p->offsety <= 512)
			p->offsety += 64;
		draw_line(p, 0 + p->offsetx , 0 + p->offsety - 64, 0x000000);
		mlx_put_image_to_window(p->mlx, p->mlx_window, p->image, 0 + p->offsetx , 0 + p->offsety);
		return (0);
	}
	else if (key == XK_w)
	{
		if (p->offsety >= 64)
			p->offsety -= 64;
		draw_line(p, 0 + p->offsetx , 0 + p->offsety + 64, 0x000000);
		mlx_put_image_to_window(p->mlx, p->mlx_window, p->image, 0 + p->offsetx , 0 + p->offsety);
		return (0);
	}
	return(0);
}

int	error()
{
	ft_printf("Error\n");
	return (0);
}

int	main(int argc, char **argv)
{
	s_data mlx;
	int	x;
	int	y;

	mlx.window_x = 640;
	mlx.window_y = 640;
	x = 64;
	y = 64;
	mlx.offsetx = 0;
	mlx.offsety = 0;
	(void)argc;
	(void)argv;
	mlx.mlx = mlx_init();
	mlx.image = mlx_xpm_file_to_image(mlx.mlx, "./test.xpm", &x,&y);
	mlx.image2 = mlx_xpm_file_to_image(mlx.mlx, "./floor.xpm", &x,&y);
	mlx.mlx_window = mlx_new_window(mlx.mlx, mlx.window_x, mlx.window_y, "Game");
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_window, mlx.image, 0, 0);
	mlx_key_hook(mlx.mlx_window, &moveup, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
