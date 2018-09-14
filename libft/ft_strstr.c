/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:18:59 by tsergien          #+#    #+#             */
/*   Updated: 2018/03/21 12:19:02 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *needle_tip;
	char *hs;
	char *result;

	hs = (char *)haystack;
	needle_tip = (char *)needle;
	if (ft_strlen(needle) == 0)
		return (hs);
	while (*hs != '\0')
	{
		result = hs;
		while (*result == *needle && *needle != '\0')
		{
			result++;
			needle++;
		}
		if (*needle == '\0')
			return (hs);
		needle = needle_tip;
		hs++;
	}
	return (0);
}
