/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:02:58 by tsergien          #+#    #+#             */
/*   Updated: 2018/03/22 14:03:07 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, \
		int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*source;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = -1;
	p = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (++i < n)
	{
		if (source[i] == uc)
		{
			*p = source[i];
			p++;
			dst = (unsigned char *)p;
			return (dst);
		}
		*p = source[i];
		p++;
	}
	return (NULL);
}
