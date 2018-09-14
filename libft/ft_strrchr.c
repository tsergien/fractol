/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:18:59 by tsergien          #+#    #+#             */
/*   Updated: 2018/03/21 12:19:02 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		ch;

	ch = (char)c;
	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	while (*s != ch && i > 0)
	{
		s--;
		i--;
	}
	if (*s == ch)
		return ((char *)s);
	return (0);
}
