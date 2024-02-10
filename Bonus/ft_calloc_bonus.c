/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:04:08 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/09 22:04:41 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	long	cnt;
	long	sz;

	cnt = (long)count;
	sz = (long)size;
	if (cnt < 0 || sz < 0)
		return (0);
	ptr = malloc(cnt * size);
	if (!ptr)
	{
		return (0);
	}
	ft_bzero(ptr, cnt * size);
	return (ptr);
}
