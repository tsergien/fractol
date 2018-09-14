/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:28:08 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/04 17:28:19 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	len_n(int cp)
{
	int len;

	len = 0;
	if (cp == 0 || cp == -0)
		return (1);
	while (cp)
	{
		cp = cp / 10;
		len++;
	}
	return (len);
}

static void	fill_s(char **s, int n, int negative, int len)
{
	char *str;

	str = *s;
	while (len)
	{
		*(str + len-- - 1 + negative) = n % 10 + '0';
		n = n / 10;
	}
}

char		*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		negative;

	negative = 0;
	len = len_n(n);
	if (n < 0)
		negative = 1;
	s = ft_strnew(len + negative);
	if (!s)
		return (0);
	if (n == -2147483648)
	{
		ft_strcpy(s, "-2147483648");
		return (s);
	}
	if (negative)
	{
		*s = '-';
		n = -n;
	}
	fill_s(&s, n, negative, len);
	return (s);
}
