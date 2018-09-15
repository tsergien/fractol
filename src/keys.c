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

static int		change_color(t_ptrs *p)
{
	clear_all(p);
	if (p->f->color == GREY_BLUE)
		p->f->color = WHITE;
	else if (p->f->color == WHITE)
		p->f->color = PINK;
	else if (p->f->color == PINK)
		p->f->color = L_RED;
	else if (p->f->color == L_RED)
		p->f->color = L_BLUE;
	else if (p->f->color == L_BLUE)
		p->f->color = D_BLUE;
	else if (p->f->color == D_BLUE)
		p->f->color = GREEN;
	else if (p->f->color == GREEN)
		p->f->color = ORANGE;
	else if (p->f->color == ORANGE)
		p->f->color = RED;
	else if (p->f->color == RED)
		p->f->color = RASPBERRY;
	else
		p->f->color = GREY_BLUE;
	draw_fract(p);
	return (0);
}

static int		next_fract(t_ptrs *p)
{
	p->f->fract = (p->f->fract + 1) % 2;
	clear_all(p);
	draw_fract(p);
	return (0);
}

static int		iter(int key, t_ptrs *p)
{
	clear_all(p);
	if (key == 27)
		p->f->iter -= 100;
	else if (key == 24)
		p->f->iter += 100;
	if (p->f->iter < 10)
		p->f->iter = 100;
	draw_fract(p);
	return (0);
}
	
int				deal_keys(int key, t_ptrs *p)
{
	if (key == 53)
		return (escape_key(key, p));
	else if (key == 8)
		return (change_color(p));
	else if (key == 49)
		return (next_fract(p));
	else if (key == 27 || key == 24)
		return (iter(key, p));
	return (0);
}
