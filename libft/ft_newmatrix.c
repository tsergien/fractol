/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:24:22 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/06 13:24:25 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	**ft_newmatrix(size_t m, size_t n, size_t size)
{
	size_t	i;
	void	**matrix;

	i = 0;
	matrix = (void **)malloc(size * n);
	while (i < n)
	{
		matrix[i] = (void *)malloc(size * m);
		i++;
	}
	matrix[i] = 0;
	return (matrix);
}
