/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:06:10 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/05 16:35:53 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ls;

	ls = (t_list *)malloc(sizeof(*ls));
	if (!ls)
		return (NULL);
	if (content == NULL)
	{
		ls->content = NULL;
		ls->content_size = 0;
		return (ls);
	}
	ls->content = malloc(content_size);
	if (!(ls->content))
	{
		free(ls);
		return (NULL);
	}
	ft_memcpy(ls->content, content, content_size);
	ls->content_size = content_size;
	ls->next = NULL;
	return (ls);
}
