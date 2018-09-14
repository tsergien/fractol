/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:18:59 by tsergien          #+#    #+#             */
/*   Updated: 2018/03/21 12:19:02 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *s)
{
	int			negative;
	size_t		result;
	size_t		old;

	negative = 0;
	result = 0;
	while (*s == 32 || (*s <= 13 && *s >= 9))
		s++;
	if (*s == '-')
		negative = 1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s <= '9' && *s >= '0')
	{
		old = result;
		result = result * 10 + *(s++) - '0';
		if (ABS(old) > ABS(result))
			return (negative ? 0 : -1);
	}
	return (negative ? -result : result);
}
