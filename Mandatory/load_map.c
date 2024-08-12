/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:58:35 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/12 17:15:12 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_w_h(t_data *obj)
{
	char	*line;

	line = NULL;
	obj->fd = open(obj->path, O_RDONLY);
	if (obj->fd == -1)
		return ;
	line = get_next_line(obj->fd);
	if (!line)
		error_msg("Empty map file", obj, 0);
	obj->map_width = ft_strlen(line) - 1;
	while (line)
	{
		obj->map_height++;
		free(line);
		line = get_next_line(obj->fd);
	}
	free(line);
}

void	if_no(char *str, t_data *obj)
{
	if (!str)
		error_msg("Empty map file", obj, 0);
}

void	fill_map_lines(t_data *obj)
{
	char	*tmp;

	tmp = NULL;
	if (!obj->map)
		return ;
	close(obj->fd);
	obj->fd = open(obj->path, O_RDONLY);
	obj->line = ft_calloc(1, 1);
	if (!obj->line)
		return ;
	tmp = get_next_line(obj->fd);
	if_no(tmp, obj);
	obj->line = ft_strjoin(obj->line, tmp, ft_strlen(tmp));
	if_no(obj->line, obj);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(obj->fd);
		obj->line = ft_strjoin(obj->line, tmp, ft_strlen(tmp));
		if_no(obj->line, obj);
	}
	if (obj->line && obj->line[ft_strlen(obj->line) - 1] == '\n')
		error_msg("Extra line break in map file", obj, 0);
	close(obj->fd);
	obj->map = ft_split(obj->line, '\n');
}

int	load_map(t_data *obj, char *path)
{
	int		j;
	int		k;
	t_img	img;
	int		fd;

	j = 0;
	k = 0;
	obj->path = path;
	fd = open(obj->path, O_RDONLY);
	if (read(fd, "", 0) == -1)
	{
		error_msg("Map file not found", obj, 0);
		destroy_images_window(&img, obj);
		close(fd);
		exit(0);
	}
	map_w_h(obj);
	fill_map_lines(obj);
	return (1);
}
