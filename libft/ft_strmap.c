/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:15:06 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/03 17:15:19 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *p;
	char *news;
	char *b;

	if (!s || !f)
		return (0);
	news = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!news)
		return (0);
	if (news == 0)
		return (0);
	b = news;
	p = (char *)s;
	while (*p != '\0')
		*news++ = f(*p++);
	*news = '\0';
	return (b);
}
