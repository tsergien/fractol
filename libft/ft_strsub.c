/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:32:44 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/03 18:32:56 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;
	char *b;

	if (!s)
		return (0);
	sub = ft_strnew(len);
	if (!sub)
		return (0);
	b = sub;
	while (len--)
		*sub++ = s[start++];
	*sub = '\0';
	return (b);
}
