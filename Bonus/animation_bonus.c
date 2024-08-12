/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:57:59 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/11 05:18:51 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_enemy(t_img *img, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init_img(img, data);
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'S')
			{
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, img->enemy_ptr, j * 60, i * 60);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	left_to_righ(t_data *data, t_img *img, char *tab)
{
	if (img->enemy_dir == 0 && finder(tab,
			data->map[img->enemy_y][img->enemy_x + 1]) == 0)
	{
		data->map[img->old_y][img->old_x] = '0';
		img->enemy_x++;
		data->map[img->enemy_y][img->enemy_x] = 'S';
	}
	else if (img->enemy_dir == 0 && finder(tab,
			data->map[img->enemy_y][img->enemy_x + 1]) == 1)
		img->enemy_dir = 1;
}

void	move_logic(t_data *data, t_img *img, int *frame_count)
{
	char	*tab;
	int		n;

	tab = "1CES";
	n = 22;
	if (*frame_count % n == 0)
	{
		left_to_righ(data, img, tab);
		if (img->enemy_dir == 1 && finder(tab,
				data->map[img->enemy_y][img->enemy_x - 1]) == 0)
		{
			data->map[img->old_y][img->old_x] = '0';
			img->enemy_x--;
			data->map[img->enemy_y][img->enemy_x] = 'S';
		}
		if (img->enemy_dir == 1 && finder(tab,
				data->map[img->enemy_y][img->enemy_x - 1]) == 1)
			img->enemy_dir = 0;
	}
}

void	move_enemy(t_game *game)
{
	static int	frame_count;
	t_data		*data;
	t_img		*img;

	data = game->data;
	img = game->img;
	img->old_x = img->enemy_x;
	img->old_y = img->enemy_y;
	move_logic(data, img, &frame_count);
	if (img->enemy_y == data->py && img->enemy_x == data->px)
	{
		you_lose();
		destroy_images_window(img, data);
		exit(0);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img->land_ptr, img->old_x * 60, img->old_y * 60);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img->enemy_ptr, img->enemy_x * 60, img->enemy_y * 60);
	frame_count++;
}

int	hook(t_game *game)
{
	t_data	*data;
	t_img	*img;
	int		i;
	int		j;

	i = 0;
	j = 0;
	data = game->data;
	img = game->img;
	init_img(img, data);
	while (data->map[++i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'S')
			{
				img->enemy_x = j;
				img->enemy_y = i;
				move_enemy(game);
			}
			j++;
		}
		j = 0;
	}
	return (0);
}
