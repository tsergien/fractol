/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:47:04 by tsergien          #+#    #+#             */
/*   Updated: 2018/04/18 15:47:05 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*init(t_gnl *lst, int fd)
{
	while (lst->next && lst->fd != fd)
		lst = lst->next;
	if (lst->fd == fd)
		return (lst);
	lst->next = (t_gnl *)malloc(sizeof(t_gnl));
	lst->next->fd = fd;
	lst->next->str = 0;
	lst->next->next = NULL;
	return (lst->next);
}

int		read_while(t_gnl *gnl)
{
	char			*buf;
	int				rt;
	int				been_read;

	been_read = 0;
	buf = ft_strnew(BUFF_SIZE);
	while ((rt = read(gnl->fd, buf, BUFF_SIZE)) > 0)
	{
		been_read = 1;
		buf[rt] = '\0';
		gnl->str = ft_strjoin_free_one(&gnl->str, buf);
		if (ft_strchr(gnl->str, DELIM))
			break ;
	}
	ft_strdel(&buf);
	if (gnl->str == NULL && !been_read)
		return (0);
	return (1);
}

int		write_to_line(char **line, t_gnl *gnl)
{
	char			*tmp;
	char			*ptr;

	if (*gnl->str == 0)
	{
		ft_strdel(&gnl->str);
		return (0);
	}
	if ((tmp = ft_strchr(gnl->str, DELIM)))
	{
		*line = ft_strsub(gnl->str, 0, tmp - gnl->str);
		*tmp++ = '\0';
		ptr = ft_strdup(tmp);
		ft_strdel(&gnl->str);
		gnl->str = ptr;
		return (1);
	}
	else
	{
		*line = ft_strdup(gnl->str);
		if (ft_strlen(*line) == 0)
			*line = NULL;
	}
	*gnl->str = 0;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*list;
	t_gnl			*gnl;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (!list)
	{
		list = (t_gnl *)malloc(sizeof(t_gnl));
		list->fd = fd;
		list->str = 0;
		list->next = NULL;
	}
	gnl = init(list, fd);
	if (!read_while(gnl))
		return (0);
	return (write_to_line(line, gnl));
}
