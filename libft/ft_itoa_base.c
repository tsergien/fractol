/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:05:31 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/02 19:05:33 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	to_base(unsigned long value)
{
	if (value <= 9)
		return ('0' + value);
	if (value > 9 && value <= 15)
		return ('a' + value - 10);
	else
		return (0);
}

char	to_base_neg(unsigned long value, int *is_last_bit)
{
	char	r;

	value = 15 - value;
	if ((value + *is_last_bit) <= 9)
	{
		r = ('0' + value + *is_last_bit);
		*is_last_bit = 0;
		return (r);
	}
	if ((value + *is_last_bit) > 9 && (value + *is_last_bit) < 16)
	{
		r = ('a' + value - 10 + *is_last_bit);
		*is_last_bit = 0;
		return (r);
	}
	else
		return ('0');
}

void	fill_s(char **s, int len, unsigned long value, size_t base)
{
	int		last_bit;

	last_bit = 1;
	while (len--)
	{
		s[0][len] = to_base(value % base);
		value = value / base;
	}
}

char	*ft_itoa_base(unsigned long value, size_t base)
{
	int		len;
	char	*s;

	len = ft_num_len(value, base);
	s = ft_strnew(len);
	fill_s(&s, len, value, base);
	return (s);
}
