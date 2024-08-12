/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:24:53 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/11 01:55:06 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	is_map_rect(t_data *obj)
{
	int	j;

	j = 0;
	while (j < obj->map_height)
	{
		if (ft_strlen(obj->map[0]) != ft_strlen(obj->map[j]))
			error_msg("Map is not rectangular", obj, 0);
		j++;
	}
}

void	enemy_number(t_data *obj)
{
	int	i;
	int	j;
	int	enemy;

	enemy = 0;
	i = 0;
	j = 0;
	while (i < obj->map_height)
	{
		while (j < obj->map_width && obj->map[i][j] != '\0')
		{
			if (obj->map[i][j] == 'S')
				enemy++;
			j++;
		}
		j = 0;
		i++;
	}
	if (enemy < 1)
		error_msg("Number of enemies must be correct", obj, 0);
}

void	items_number(t_data *obj)
{
	int	i;
	int	j;
	int	player;
	int	door;

	obj->collectible = 0;
	i = 0;
	j = 0;
	player = 0;
	door = 0;
	while (++i < obj->map_height)
	{
		while (++j < obj->map_width && obj->map[i][j] != '\0')
		{
			if (obj->map[i][j] == 'P')
				player++;
			if (obj->map[i][j] == 'E')
				door++;
			if (obj->map[i][j] == 'C')
				obj->collectible++;
		}
		j = 0;
	}
	if (player != 1 || door != 1 || obj->collectible < 1)
		error_msg("Number of items must be correct", obj, 0);
}

void	ones_frame(t_data *obj)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < obj->map_width)
	{
		if (obj->map[0][i] != '1' || obj->map[obj->map_height - 1][i] != '1')
			error_msg("Map is not round by ones", obj, 0);
		i++;
	}
	while (j < obj->map_height)
	{
		if (obj->map[j][0] != '1' || obj->map[j][obj->map_width - 1] != '1')
			error_msg("Map not rounded by ones", obj, 0);
		j++;
	}
}

int	check_map(t_data *obj)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	is_map_rect(obj);
	items_number(obj);
	enemy_number(obj);
	while (i < obj->map_height)
	{
		while (j < obj->map_width && obj->map[i][j] != '\0')
		{
			if (obj->map[i][j] != '1' && obj->map[i][j] != '0'
			&& obj->map[i][j] != 'C' && obj->map[i][j] != 'E'
			&& obj->map[i][j] != 'P' && obj->map[i][j] != 'S')
				error_msg("Map must contain only 0, 1, C, E, P, S", obj, 0);
			j++;
		}
		j = 0;
		i++;
	}
	ones_frame(obj);
	return (1);
}
