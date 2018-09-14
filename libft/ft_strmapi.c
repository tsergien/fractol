/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:24:52 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/03 17:25:06 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*p;
	char			*news;
	char			*b;

	i = 0;
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
	{
		*news = f(i, *p);
		news++;
		p++;
		i++;
	}
	*news = '\0';
	return (b);
}
