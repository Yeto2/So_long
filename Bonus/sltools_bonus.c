/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sltools_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:31:55 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/09 22:38:33 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exit_press(t_game *game)
{
	t_data	*data;
	t_img	*img;

	data = game->data;
	img = game->img;
	destroy_images_window(img, data);
	exit(0);
	return (0);
}
