/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 02:27:12 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/09 21:38:57 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_data *data)
{
	data->moves = 0;
	data->keycodes = 0;
	data->map_height = 0;
	data->tab_imgs = malloc(sizeof(void *) * 7);
}

void	destroy_images(t_img *img, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, img->wall_ptr);
	mlx_destroy_image(data->mlx_ptr, img->coin_ptr);
	mlx_destroy_image(data->mlx_ptr, img->person_ptr);
	mlx_destroy_image(data->mlx_ptr, img->rperson_ptr);
	mlx_destroy_image(data->mlx_ptr, img->land_ptr);
	mlx_destroy_image(data->mlx_ptr, img->op_door_ptr);
	mlx_destroy_image(data->mlx_ptr, img->cl_door_ptr);
}

void	destroy_images_window(t_img *img, t_data *data)
{
	destroy_images(img, data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

void	*is_valid(t_data *data, char *file_name, int i)
{
	void	*imgd_p;
	int		n;

	imgd_p = mlx_xpm_file_to_image(data->mlx_ptr, file_name, &n, &n);
	if (!imgd_p)
	{
		while (i <= 0)
		{
			mlx_destroy_image(data->mlx_ptr, data->tab_imgs[i]);
			i--;
		}
		ft_putendl_fd(RED_TEXT "\nERROR:\n", 2);
		write(2, "         ", 9);
		write(2, "invalid image file", 18);
		write(2, "\n\n", 2);
		exit(0);
	}
	return (imgd_p);
}

void	init_img(t_img *img, t_data *data)
{
	img->wall_ptr = is_valid(data, "Mandatory/img/wall.xpm", 0);
	data->tab_imgs[0] = img->wall_ptr;
	img->coin_ptr = is_valid(data, "Mandatory/img/coin.xpm", 1);
	data->tab_imgs[1] = img->coin_ptr;
	img->person_ptr = is_valid(data, "Mandatory/img/player.xpm", 2);
	data->tab_imgs[2] = img->person_ptr;
	img->rperson_ptr = is_valid(data, "Mandatory/img/rplayer.xpm", 3);
	data->tab_imgs[3] = img->rperson_ptr;
	img->land_ptr = is_valid(data, "Mandatory/img/land.xpm", 4);
	data->tab_imgs[4] = img->land_ptr;
	img->op_door_ptr = is_valid(data, "Mandatory/img/oppend_door.xpm", 5);
	data->tab_imgs[5] = img->op_door_ptr;
	img->cl_door_ptr = is_valid(data, "Mandatory/img/closed_door.xpm", 6);
	data->tab_imgs[6] = img->cl_door_ptr;
}
