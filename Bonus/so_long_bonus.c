/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 04:54:43 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/12 17:17:13 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img(t_data *data)
{
	t_img	img;

	init_img(&img, data);
	if (data->map[data->py][data->px] != '1')
		data->moves++;
	if (data->map[data->py][data->px] == 'C')
	{
		data->collectible--;
		data->map[data->py][data->px] = '0';
	}
	if (data->map[data->py][data->px] == 'E' && data->collectible == 0)
	{
		you_win();
		destroy_images_window(&img, data);
		exit(0);
	}
	if (data->map[data->py][data->px] == 'S')
	{
		destroy_images_window(&img, data);
		you_lose();
		exit(0);
	}
}

void	event_listner(int key, t_data *data)
{
	if (key == 53 || key == 17)
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
	int		old_x;
	int		old_y;
	char	*str;

	data->keycodes = keycode;
	old_x = data->px;
	old_y = data->py;
	event_listner(keycode, data);
	str = ft_itoa(data->moves);
	if (!str)
		return (0);
	mlx_string_put(data->mlx_ptr,
		data->win_ptr, 20, 10, 0x00FFFFFF, "Moves : ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 10, 0x00FFFFFF, str);
	free(str);
	return (0);
}

void	ac_load(int ac, char *av, t_data *data, t_img *img)
{
	(void)img;
	if (ac == 2)
		load_map(data, av);
	else
		error_msg("Two arguments required", data, 0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_img	img;
	t_game	game;

	img.frame = 0;
	init_vars(&data);
	ac_load(ac, av[1], &data, &img);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		error_msg("Failed to create a mlx pointer", &data, 0);
	check_map(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			data.map_width * 60, data.map_height * 60, "Desert !!!");
	if (!data.win_ptr)
		error_msg("Failed to create a window", &data, 0);
	set_items(&data, 0);
	helper(&data, data.px, data.py);
	mlx_hook(data.win_ptr, 2, 0, on_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, exit_press, &game);
	set_enemy(&img, &data);
	game.data = &data;
	game.img = &img;
	mlx_loop_hook(data.mlx_ptr, hook, &game);
	mlx_loop(data.mlx_ptr);
	return (0);
}
