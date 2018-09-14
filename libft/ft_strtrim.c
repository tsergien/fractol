/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:06:44 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/03 19:06:59 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	separator(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t		len;
	char		*news;
	const char	*start;
	const char	*end;

	if (!s)
		return (0);
	len = 0;
	while (separator(*s) && *s != '\0')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	start = s;
	while (*s != '\0')
		s++;
	s--;
	while (separator(*s) && *s != '\0')
		s--;
	end = s;
	news = ft_strnew(end - start + 1);
	if (!news)
		return (0);
	ft_strcpy(news, start);
	news[end - start + 1] = '\0';
	return (news);
}
