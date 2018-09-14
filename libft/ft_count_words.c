/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_wrods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:20:14 by tsergien          #+#    #+#             */
/*   Updated: 2018/08/17 14:20:16 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			separator(char c)
{
	if (c == ' ' || c == '\n' ||
	(c >= 9 && c <= 13) || c == '\0')
		return (1);
	return (0);
}

int			count_words(char *line)
{
	int		w;
	int		flag;

	w = 0;
	while (*line)
	{
		if (!separator(*line))
			w++;
		while (*line && !separator(*line))
			line++;
		while (*line && separator(*line))
			line++;
	}
	return (w);
}
