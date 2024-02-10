/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:01:14 by yessemna          #+#    #+#             */
/*   Updated: 2024/02/09 22:07:50 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	slen ;

	i = 0;
	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_calloc(1, 1));
	if (len >= slen - start)
		len = slen - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (len--)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
