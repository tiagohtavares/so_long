/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:53:43 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/20 16:48:58 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	void	*img_enemy1;
	void	*img_enemy2;
	void	*img_bomb;
	void	*img_fire;
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
	int		totalenemy;
	int		totalframe;
	int		frame;
	int		bomb_on;
	int		bombx;
	int		enemy_alive;
	int		bomby;
}	t_data;

void	clear_fire(t_data *gameinfo);
void	move_enemy_side(t_data *gameinfo, int x, int y, int now);
void	move_enemy_top(t_data *gameinfo, int x, int y, int now);
void	destroy_enemy(t_data *gameinfo, int x, int y, int type);
void	explode(t_data *gameinfo);
int		animate_two(t_data *gameinfo);
int		animate_one(t_data *gameinfo);
void	animate_enemy(t_data *gameinfo, int x, int y);
void	delay(t_data *gameinfo);
void	animate_bomb(t_data *gameinfo);
int		find_positionx(t_data *gameinfo);
int		find_positiony(t_data *gameinfo);
int		bomb(t_data *gameinfo);
int		animate_one(t_data *gameinfo);
int		animate_two(t_data *gameinfo);
void	clear_exit(t_data *gameinfo);
void	dupe_map(t_data *gameinfo);
void	find_position_duped(t_data *gameinfo);
void	clear_duped(t_data *gameinfo);
int		animate(t_data *gameinfo);
void	load_enemy(t_data *gameinfo);
void	total_enemy(t_data *gameinfo);
void	check_enemy(t_data *gameinfo);
void	find_position(t_data *gameinfo);
void	check_empty(t_data *gameinfo);
void	check_rectangle(t_data *gameinfo);
void	flood_fill(t_data *gameinfo);
void	check_path(t_data *gameinfo);
int		exit_clean(t_data *gameinfo);
int		drawmap(t_data *gameinfo);
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
