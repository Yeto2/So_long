/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:36:42 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/12 17:17:43 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# define RED_TEXT   "\x1B[31m"
# define GREEN_TEXT   "\x1B[32m"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**d_map;
	int		fd;
	char	*line;
	char	**map;
	int		map_width;
	int		map_height;
	int		collectible;
	int		px;
	int		py;
	int		ppos_x;
	int		ppos_y;
	int		moves;
	int		keycodes;
	char	*path;
	void	**tab_imgs;
}	t_data;

typedef struct s_img
{
	void	*wall_ptr;
	void	*coin_ptr;
	void	*person_ptr;
	void	*rperson_ptr;
	void	*land_ptr;
	void	*op_door_ptr;
	void	*enemy_ptr;
	void	*cl_door_ptr;
	int		img_width;
	int		img_height;
	int		coin_x;
	int		coin_y;
}	t_img;

typedef struct s_game
{
	t_data	*data;
	t_img	*img;
}	t_game;

int		check_map(t_data *obj);
void	set_items(t_data *data, int n);
int		load_map(t_data *obj, char *path);
int		exit_press(t_game *game);
void	error_msg(char *msg, t_data *obj, int n);
void	init_vars(t_data *data);
void	init_img(t_img *img, t_data *data);
void	flood_fill(t_data *obj, int i, int j, int *count_itmes);
int		helper(t_data *obj, int px, int py);
void	set_path(t_data *data, char *path);
char	*you_win(void);
void	destroy_images_window(t_img *img, t_data *data);
void	destroy_images(t_img *img, t_data *data);
char	*get_next_line(int fd);
char	*fill_line_buffer(int fd, char *buffer);
char	*ft_strjoin(char const *s1, char const *s2, int index);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	ft_putendl_fd(char *s, int fd);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif