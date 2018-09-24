/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:42:18 by tsergien          #+#    #+#             */
/*   Updated: 2018/09/13 11:42:41 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		escape_key(int key, t_ptrs *p)
{
	(void)p;
	if (key == 53)
		exit(0);
	return (0);
}

static int		next_fract(t_ptrs *p)
{
	p->f->fract = (p->f->fract + 1) % 3;
	launch_threads(p);
	return (0);
}

static int		iter(int key, t_ptrs *p)
{
	if (key == 27)
		p->f->iter -= 20;
	else if (key == 24)
		p->f->iter += 20;
	if (p->f->iter < 2)
		p->f->iter = 2;
	launch_threads(p);
	return (0);
}

static int		reset(t_ptrs *p)
{
	p->f->zoom = 1;
	p->f->shift.x = 0;
	p->f->shift.y = 0;
	launch_threads(p);
	return (0);
}

int				deal_keys(int key, t_ptrs *p)
{
	if (key == 53)
		return (escape_key(key, p));
	else if (key == 49)
		return (next_fract(p));
	else if (key == 27 || key == 24)
		return (iter(key, p));
	else if (key > 122 && key < 127)
		return (shifting(key, p));
	else if (key == 69 || key == 78)
		return (zooming(key, p));
	else if (key == 36)
		return (reset(p));
	else if (key == 8)
		return (change_palette(key, p));
	return (0);
}
