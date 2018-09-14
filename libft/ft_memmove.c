/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:51:49 by tsergien          #+#    #+#             */
/*   Updated: 2018/03/22 16:51:52 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p;
	unsigned char	*source;

	p = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (src > dst)
	{
		while (len--)
		{
			*p = *source;
			p++;
			source++;
		}
	}
	else
	{
		while (len--)
			*(p + len) = *(source + len);
	}
	return (dst);
}
