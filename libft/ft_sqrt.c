/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:32:07 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/06 13:32:09 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_sqrt(size_t n)
{
	size_t		res;

	res = n / 2;
	if (res % 2 == 0 && n % 2 == 1)
		res++;
	if (n == 0 || n == 1)
		return (n);
	while (res > 1)
	{
		if (res * res == n)
		{
			return (res);
		}
		res = res - 2;
	}
	return (-1);
}
