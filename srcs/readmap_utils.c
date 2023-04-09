/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:55:29 by ttavares          #+#    #+#             */
/*   Updated: 2023/04/09 07:42:46 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	windowsize(t_data *gameinfo)
{
	int	i;

	i = 0;
	gameinfo->windowx = 0;
	gameinfo->windowy = 0;
	while (gameinfo->map[0][i])
	{
		gameinfo->windowx++;
		i++;
	}
	i = 0;
	while (gameinfo->map[i])
	{
		gameinfo->windowy++;
		i++;
	}
}

void	printmap(t_data *gameinfo)
{
	int		i;

	i = 0;
	while (gameinfo->map[i])
	{
		ft_printf("%s \n", gameinfo->map[i]);
		i++;
	}
}

void	clearmap(t_data *gameinfo)
{
	int	i;

	i = 0;
	while (gameinfo->map[i])
	{
		free(gameinfo->map[i]);
		i++;
	}
	free(gameinfo->map);
}
