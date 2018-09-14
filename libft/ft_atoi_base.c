/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 13:42:12 by tsergien          #+#    #+#             */
/*   Updated: 2018/08/21 13:42:13 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	get_base(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c == 'a' || c == 'A')
		return (10);
	else if (c == 'b' || c == 'B')
		return (11);
	else if (c == 'c' || c == 'C')
		return (12);
	else if (c == 'd' || c == 'D')
		return (13);
	else if (c == 'e' || c == 'E')
		return (14);
	else if (c == 'f' || c == 'F')
		return (15);
	else
		return (0);
}

int			ft_atoi_base(const char *s, int base)
{
	int			negative;
	size_t		result;
	size_t		old;

	negative = 0;
	result = 0;
	while (*s == 32 || (*s <= 13 && *s >= 9))
		s++;
	if (*s == '-' && base == 10)
		negative = 1;
	if ((*s == '-' || *s == '+') && base == 10)
		s++;
	if (*s == '0' && *(s + 1) == 'x')
		s += 2;
	while ((*s <= '9' && *s >= '0') || (*s >= 'a' && *s <= 'f')
			|| (*s >= 'A' && *s <= 'F'))
	{
		old = result;
		result = result * base + get_base(*(s++));
		if (ABS(old) > ABS(result))
			return (negative ? 0 : -1);
	}
	return (negative ? -result : result);
}
