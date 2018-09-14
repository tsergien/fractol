/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:53:51 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/05 17:54:13 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*l;
	t_list	*new_list;
	t_list	*fl;

	if (!lst || !f)
		return (NULL);
	fl = f(lst);
	new_list = ft_lstnew(fl->content, fl->content_size);
	if (new_list != NULL)
	{
		l = new_list;
		lst = lst->next;
		while (lst)
		{
			fl = f(lst);
			l->next = ft_lstnew(fl->content, fl->content_size);
			if (l->next == NULL)
				return (NULL);
			l = l->next;
			lst = lst->next;
		}
	}
	return (new_list);
}
