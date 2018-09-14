/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:07:43 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/06 13:07:57 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstpush_back(t_list **alst, t_list *new)
{
	t_list	*current;

	if (!alst || !new)
		return ;
	current = *alst;
	if (!current)
	{
		*alst = new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new;
	new->next = NULL;
}
