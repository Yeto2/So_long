/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 02:37:27 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/09 06:20:33 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*you_win(void)
{
	ft_putendl_fd(GREEN_TEXT
		"    ██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗██╗███╗   ██╗", 1);
	ft_putendl_fd(GREEN_TEXT
		"    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██║████╗  ██║", 1);
	ft_putendl_fd(GREEN_TEXT
		"     ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║", 1);
	ft_putendl_fd(GREEN_TEXT
		"      ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║██║╚██╗██║", 1);
	ft_putendl_fd(GREEN_TEXT
		"       ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║", 1);
	ft_putendl_fd(GREEN_TEXT
		"       ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝", 1);
	return (0);
}

void	error_msg(char *msg, t_data *obj, int n)
{
	t_img	img;

	if (n == 1)
	{
		init_img(&img, obj);
		destroy_images(&img, obj);
	}
	ft_putendl_fd(RED_TEXT "\nERROR:\n", 2);
	write(2, "         ", 9);
	write(2, msg, ft_strlen(msg));
	write(2, "\n\n", 2);
	exit(0);
}
