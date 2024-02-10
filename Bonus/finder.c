/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:20:14 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/09 22:04:18 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	finder(const char *s, int c)
{
	unsigned char	cr;
	char			*str;
	int				i;

	i = 0;
	cr = (unsigned char)c;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == cr)
			return (1);
		i++;
	}
	return (0);
}
