/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:24:56 by tsergien          #+#    #+#             */
/*   Updated: 2018/03/21 12:24:58 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*p;
	unsigned char	*source;
	size_t			i;

	i = 0;
	p = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (i < n)
	{
		*(p + i) = *(source + i);
		i++;
	}
	return (dst);
}
