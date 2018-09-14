/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_one2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:11:56 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/08 14:11:58 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin_free_one2(char const *s1, char **s2)
{
	char			*p;
	char			*b;
	unsigned long	len;
	unsigned long	i;

	i = 0;
	if (!s2 || (!(*s2) && !(s1)))
		return (0);
	len = ft_strlen(*s2) + ft_strlen(s1);
	p = ft_strnew(len);
	b = p;
	if (!p)
		return (0);
	i = 0;
	while (*(s1 + i))
		*p++ = *(s1 + i++);
	i = 0;
	while (*s2 && *(*s2 + i))
		*p++ = *(*s2 + i++);
	ft_strdel(s2);
	return (b);
}
