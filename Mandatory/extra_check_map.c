/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:58:07 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/09 21:35:12 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	check_ext(t_data *obj)
{
	char	*ext;

	ext = strchr(obj->path, '.');
	if (ext[0] != '.' || ext[1] != 'b' || ext[2] != 'e' || ext[3] != 'r')
		error_msg("Map file extension is not .ber", obj, 1);
}
