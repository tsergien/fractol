/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:22:00 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/06 13:22:01 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin_free_one(char **s1, char const *s2)
{
	char			*p;
	char			*b;
	unsigned long	len;
	unsigned long	i;

	i = 0;
	if (!s1 || (!(*s1) && !(s2)))
		return (0);
	len = ft_strlen(*s1) + ft_strlen(s2);
	p = ft_strnew(len);
	b = p;
	if (!p)
		return (0);
	i = 0;
	while (*s1 && *(*s1 + i))
		*p++ = *(*s1 + i++);
	i = 0;
	while (*(s2 + i))
		*p++ = *(s2 + i++);
	ft_strdel(s1);
	return (b);
}
