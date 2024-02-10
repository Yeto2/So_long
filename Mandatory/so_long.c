/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 04:54:43 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/09 21:39:15 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_data *data)
{
	t_img	img;

	init_img(&img, data);
	if (data->map[data->py][data->px] != '1')
	{
		data->moves++;
		write(1, "moves : ", 8);
		ft_putnbr_fd(data->moves, 1);
		write(1, "\n", 1);
	}
	if (data->map[data->py][data->px] == 'C')
	{
		data->collectible--;
		data->map[data->py][data->px] = '0';
	}
	if (data->map[data->py][data->px] == 'E' &&
		data->collectible == 0)
	{
		you_win();
		destroy_images_window(&img, data);
		exit(0);
	}
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
	while (i < 7)
	{
		mlx_destroy_image(data->mlx_ptr, data->tab_imgs[i]);
		i++;
	}
	free(data->map);
	free(data->tab_imgs);
	exit(1);
}

void	event_listner(int key, t_data *data)
{
	if (key == 53)
		free_map(data);
	if ((key == 13 || key == 126) && data->map[data->py - 1][data->px] != '1')
	{
		data->py -= 1;
		put_img(data);
	}
	if ((key == 1 || key == 125) && data->map[data->py + 1][data->px] != '1')
	{
		data->py += 1;
		put_img(data);
	}
	if ((key == 0 || key == 123) && data->map[data->py][data->px - 1] != '1')
	{
		data->px -= 1;
		put_img(data);
	}
	if ((key == 2 || key == 124) && data->map[data->py][data->px + 1] != '1')
	{
		data->px += 1;
		put_img(data);
	}
	set_items(data, 1);
}

int	on_keypress(int keycode, t_data *data)
{
	int	old_x;
	int	old_y;

	data->keycodes = keycode;
	old_x = data->px;
	old_y = data->py;
	event_listner(keycode, data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_img	img;
	t_game	game;

	init_vars(&data);
	if (ac == 2)
		load_map(&data, av[1]);
	else
		error_msg("More than two arguments", &data, 0);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		error_msg("Failed to create mlx pointer", &data, 0);
	check_map(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map_width * 60,
			data.map_height * 60, "Desert !!!");
	if (!data.win_ptr)
		error_msg("Window creation failed", &data, 0);
	set_items(&data, 0);
	helper(&data, data.px, data.py);
	mlx_hook(data.win_ptr, 17, 0, exit_press, &game);
	mlx_hook(data.win_ptr, 2, 0, on_keypress, &data);
	game.data = &data;
	game.img = &img;
	mlx_loop(data.mlx_ptr);
	return (0);
}
