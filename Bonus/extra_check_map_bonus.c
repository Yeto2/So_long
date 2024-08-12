/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_check_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:58:07 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/12 17:16:48 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(t_data *obj, int i, int j, int *count_itmes)
{
	if (i < 0 || j < 0 || i >= obj->map_width || j >= obj->map_height
		|| obj->d_map[j][i] == '1' || obj->d_map[j][i] == 'x')
		return ;
	if (obj->d_map[j][i] == 'C' || obj->d_map[j][i] == 'E')
		*count_itmes += 1;
	obj->d_map[j][i] = 'x';
	flood_fill(obj, i + 1, j, count_itmes);
	flood_fill(obj, i - 1, j, count_itmes);
	flood_fill(obj, i, j + 1, count_itmes);
	flood_fill(obj, i, j - 1, count_itmes);
}

int	helper(t_data *obj, int px, int py)
{
	int		count_itmes;
	int		i;

	count_itmes = 0;
	i = 0;
	obj->d_map = ft_split(obj->line, '\n');
	flood_fill(obj, px, py, &count_itmes);
	while (obj->d_map[i])
	{
		free(obj->d_map[i]);
		i++;
	}
	free (obj->d_map);
	if (obj->collectible + 1 != count_itmes)
		error_msg("Elements are not reachable", obj, 1);
	return (1);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		mlx_destroy_image(data->mlx_ptr, data->tab_imgs[i]);
		i++;
	}
	free(data->map);
	free(data->tab_imgs);
	exit(1);
}
