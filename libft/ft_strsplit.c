/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:01:32 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/04 15:01:49 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	count_wordss(char const *s, char c)
{
	int		res;

	if (!s)
		return (0);
	res = 0;
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			res++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (res);
}

static int	len_till_c(const char *ptr, char c)
{
	int		i;

	i = 0;
	while (*ptr == c)
		ptr++;
	while (*ptr != c && *ptr)
	{
		ptr++;
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *ptr, char c)
{
	char	**news;
	int		i;

	i = 0;
	if (!ptr || !c)
		return (NULL);
	if (!(news = (char **)malloc(sizeof(char *) * (count_wordss(ptr, c) + 1))))
		return (0);
	while (*ptr)
	{
		while (*ptr == c && *ptr)
			ptr++;
		if (*ptr == '\0')
			break ;
		if (!(news[i] = ft_strnew(len_till_c(ptr, c))))
		{
			news[0] = 0;
			return (news);
		}
		ft_strncpy(news[i], ptr, len_till_c(ptr, c));
		ptr = ptr + len_till_c(ptr, c);
		i++;
	}
	news[i] = 0;
	return (news);
}
