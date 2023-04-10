/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:57:18 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/11 00:26:00 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	load_enemy(t_data *gameinfo)
{
	gameinfo->img_enemy1 = mlx_xpm_file_to_image
		(gameinfo->mlx, "assets/sprites/slime1.xpm",
			gameinfo->imagex, gameinfo->imagey);
	gameinfo->img_enemy2 = mlx_xpm_file_to_image
		(gameinfo->mlx, "assets/sprites/slime2.xpm",
			gameinfo->imagex, gameinfo->imagey);
}

void	load_images(t_data *gameinfo)
{
	int	x;
	int	y;

	y = 64;
	x = 64;
	gameinfo->imagex = &x;
	gameinfo->imagey = &y;
	gameinfo->img_player = mlx_xpm_file_to_image
		(gameinfo->mlx, "assets/sprites/Player.xpm",
			gameinfo->imagex, gameinfo->imagey);
	gameinfo->img_wall = mlx_xpm_file_to_image
		(gameinfo->mlx, "assets/sprites/wall.xpm",
			gameinfo->imagex, gameinfo->imagey);
	gameinfo->img_collect = mlx_xpm_file_to_image
		(gameinfo->mlx, "assets/sprites/collect.xpm",
			gameinfo->imagex, gameinfo->imagey);
	gameinfo->img_exit = mlx_xpm_file_to_image
		(gameinfo->mlx, "assets/sprites/exit.xpm",
			gameinfo->imagex, gameinfo->imagey);
	gameinfo->img_floor = mlx_xpm_file_to_image
		(gameinfo->mlx, "assets/sprites/floor.xpm",
			gameinfo->imagex, gameinfo->imagey);
}

void	check_empty_line(char *line, t_data *gameinfo)
{
	int	i;

	i = 0;
	gameinfo->emptyline = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			gameinfo->emptyline = 1;
		i++;
	}
}

void	read_map(char *filepath, t_data *gameinfo)
{
	int		fd;
	char	*line;
	char	*all_lines;
	char	*temp;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		error(0, gameinfo);
	all_lines = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = all_lines;
		all_lines = ft_strjoin(temp, line);
		free(line);
		free(temp);
	}
	close(fd);
	check_empty_line(all_lines, gameinfo);
	gameinfo->map = ft_split(all_lines, '\n');
	free(all_lines);
}
