/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 05:06:30 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/02 21:52:27 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*free_buff(char *buffer, int index)
{
	int	i;

	i = 0;
	if (index == -1)
		index = BUFFER_SIZE;
	while (buffer[i + index])
	{
		buffer[i] = buffer[i + index + 1];
		i++;
	}
	while (buffer[i])
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}

int	check_nl(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*fill_line_buffer(int fd, char *buffer)
{
	int		is_nl;
	char	*line;

	line = NULL;
	is_nl = check_nl(buffer);
	line = ft_strjoin(line, buffer, is_nl + 1);
	buffer = free_buff(buffer, is_nl);
	while (is_nl == -1 && read(fd, buffer, BUFFER_SIZE))
	{
		is_nl = check_nl(buffer);
		line = ft_strjoin(line, buffer, is_nl + 1);
		buffer = free_buff(buffer, is_nl);
	}
	if (ft_strlen(line) == 0)
	{
		buffer = free_buff(buffer, -1);
		return (free(line), NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[(unsigned int)BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (read(fd, buffer, 0) == -1)
	{
		free_buff(buffer, -1);
		return (NULL);
	}
	line = fill_line_buffer(fd, buffer);
	if (!line)
		return (NULL);
	return (line);
}
