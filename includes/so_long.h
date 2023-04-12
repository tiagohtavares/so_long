/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:53:43 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/12 15:10:01 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../includes/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef struct s_data
{
	void	*mlx;
	void	*img_player;
	void	*img_floor;
	void	*img_wall;
	void	*img_collect;
	void	*img_exit;
	void	*mlx_window;
	char	**map;
	char	**duped_map;
	int		*imagex;
	int		*imagey;
	int		windowx;
	int		windowy;
	int		moves;
	int		duped_positionx;
	int		duped_positiony;
	int		positionx;
	int		positiony;
	int		collected;
	int		emptyline;
	int		totalcollectables;
}	t_data;

void	find_position_duped(t_data *gameinfo);
void	clear_duped(t_data *gameinfo);
void	find_position(t_data *gameinfo);
void	check_empty(t_data *gameinfo);
void	check_rectangle(t_data *gameinfo);
void	flood_fill(t_data *gameinfo);
void	check_path(t_data *gameinfo);
int		exit_clean(t_data *gameinfo);
void	drawmap(t_data *gameinfo);
void	printmap(t_data *gameinfo);
void	clearmap(t_data *gameinfo);
void	check_map(t_data *gameinfo);
void	windowsize(t_data *gameinfo);
void	load_images(t_data *gameinfo);
void	moves(int key, t_data *gameinfo);
void	error(int type, t_data *gameinfo);
void	read_map(char *filepath, t_data *gameinfo);
void	update_position(t_data *gameinfo, char type);
int		move_isvalid(t_data *gameinfo, char type);

#endif
