/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:43:44 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/09 22:30:05 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	door_wall_coin(t_data *data, t_img *img, int i, int j)
{
	if (data->map[i][j] == 'E')
	{
		if (data->collectible == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				img->op_door_ptr, j * 60, i * 60);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				img->cl_door_ptr, j * 60, i * 60);
	}
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->wall_ptr, j * 60, i * 60);
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->coin_ptr, j * 60, i * 60);
}

void	put_to_window(t_data *data, t_img *img, int n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	init_img(img, data);
	while (i < data->map_height)
	{
		while (j < data->map_width)
		{
			if (data->map[i][j] && data->map[i][j] != 'S')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					img->land_ptr, j * 60, i * 60);
			door_wall_coin(data, img, i, j);
			if (data->map[i][j] == 'P' && n == 0)
			{
				data->px = j;
				data->py = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	set_items(t_data *data, int n)
{
	t_img	img;

	put_to_window(data, &img, n);
	if (data->keycodes == 124)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.rperson_ptr,
			data->px * 60, data->py * 60);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.person_ptr,
			data->px * 60, data->py * 60);
}
