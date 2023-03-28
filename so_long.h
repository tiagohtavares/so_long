/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:27:18 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/28 16:42:41 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

	typedef struct t_data
	{
	void	*mlx;
	void	*image;
	void	*mlx_window;
	int		offsetx;
	int		offsety;
	int		window_x;
	int		window_y;
	}	s_data;

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

#endif
