/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:35:42 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/03 16:36:24 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *s;
	char *ptr;

	s = (char *)ft_memalloc(size + 1);
	ptr = s;
	if (s == 0)
		return (0);
	while (size > 0)
	{
		*ptr++ = '\0';
		size--;
	}
	return (s);
}
