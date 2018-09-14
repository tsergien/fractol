/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:53:16 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/03 14:53:18 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = 0;
	mem = (void *)malloc(size);
	if (mem == 0)
		return (0);
	else
		ft_bzero(mem, size);
	return (mem);
}
