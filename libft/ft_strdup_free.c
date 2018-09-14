/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:12:18 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/06 13:12:22 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup_free(char **s1)
{
	char	*dup;
	int		i;

	dup = ft_strnew(ft_strlen(*s1));
	if (!dup || !s1 || !(*s1))
		return (NULL);
	i = 0;
	while (*(*s1 + i) != '\0')
	{
		dup[i] = *(*s1 + i);
		i++;
	}
	ft_strdel(s1);
	return (dup);
}
