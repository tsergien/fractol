/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:19:26 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/06 13:19:30 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin_free(char **s1, char **s2)
{
	char			*p;
	char			*b;
	unsigned long	len;
	unsigned long	i;

	if (!s1 && !s2)
		return (0);
	len = ft_strlen(*s1) + ft_strlen(*s2);
	p = ft_strnew(len);
	b = p;
	if (!p)
		return (0);
	i = 0;
	while (*(*s1 + i))
		*p++ = *(*s1 + i++);
	i = 0;
	while (*(*s2 + i))
		*p++ = *(*s2 + i++);
	ft_strdel(s1);
	ft_strdel(s2);
	return (b);
}
