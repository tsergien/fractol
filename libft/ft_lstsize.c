/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:48:28 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/07 12:48:31 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*current;
	size_t	len;

	current = lst;
	len = 0;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}
