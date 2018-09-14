/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:18:59 by tsergien          #+#    #+#             */
/*   Updated: 2018/03/21 12:19:02 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, \
		size_t dstsize)
{
	unsigned long	j;
	unsigned long	len_dst;
	unsigned long	res;

	len_dst = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	j = 0;
	if (len_dst <= dstsize)
		res = ft_strlen(src) + len_dst;
	else
		res = ft_strlen(src) + dstsize;
	while (src[j] != '\0' && len_dst < dstsize - 1)
		dst[len_dst++] = src[j++];
	dst[len_dst++] = '\0';
	return (res);
}
