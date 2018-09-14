/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:54:47 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/05 16:54:58 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;
	t_list *next;

	if (!alst || !del)
		return ;
	current = *alst;
	while (current)
	{
		if (current->next)
			next = current->next;
		else
			next = 0;
		ft_lstdelone(&current, del);
		current = next;
	}
	*alst = 0;
}
