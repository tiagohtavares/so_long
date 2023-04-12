/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:55:28 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/12 20:26:37 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	keys(int key, t_data *gameinfo)
{
	if (key == XK_Escape)
		error(1, gameinfo);
	else
		moves(key, gameinfo);
	return (0);
}

int	x_button(t_data *gameinfo)
{
	exit_clean(gameinfo);
	return (0);
}

void	start_mlx(t_data *gameinfo)
{
	gameinfo->collected = 0;
	gameinfo->frame = 0;
	gameinfo->totalframe = 0;
	gameinfo->mlx = mlx_init();
	gameinfo->mlx_window = mlx_new_window(gameinfo->mlx, gameinfo->windowx * 64,
			gameinfo->windowy * 64, "so_long");
	load_images(gameinfo);
	load_enemy(gameinfo);
	drawmap(gameinfo);
	mlx_loop_hook(gameinfo->mlx, drawmap, gameinfo);
	mlx_hook(gameinfo->mlx_window, 17, (1L << 0), x_button, gameinfo);
	mlx_key_hook(gameinfo->mlx_window, &keys, gameinfo);
	mlx_loop(gameinfo->mlx);
}

void	check_arg(char *type)
{
	char	*tmp;
	size_t	i;
	int		j;

	j = 0;
	tmp = ".ber";
	i = 0;
	while (i < ft_strlen(type) - 4)
		i++;
	while (i < ft_strlen(type))
	{
		if (type[i] != tmp[j])
		{
			ft_printf("Error\n");
			ft_printf("Wrong map file, try .ber");
			exit(0);
		}
		i++;
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_data	gameinfo;

	gameinfo.moves = 0;
	if (argc == 2)
	{
		check_arg(argv[1]);
		read_map(argv[1], &gameinfo);
		if (gameinfo.map[0] == NULL)
			error(0, &gameinfo);
		windowsize(&gameinfo);
		check_map(&gameinfo);
		start_mlx(&gameinfo);
		clearmap(&gameinfo);
	}
	else
		ft_printf("Error\n");
	return (0);
}
