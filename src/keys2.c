/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:17:50 by tsergien          #+#    #+#             */
/*   Updated: 2018/09/16 15:17:52 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		shifting(int key, t_ptrs *p)
{
	if (key == 126)
		p->f->shift.y -= 10;
	else if (key == 125)
		p->f->shift.y += 10;
	else if (key == 123)
		p->f->shift.x -= 10;
	else if (key == 124)
		p->f->shift.x += 10;
	launch_threads(p);
	return (0);
}

int		zooming(int key, t_ptrs *p)
{
	if (key == 69)
		p->f->zoom *= 1.05;
	else if (key == 78)
		p->f->zoom *= 0.95;
	if (p->f->zoom < 0)
		p->f->zoom = 0.01;
	launch_threads(p);
	return (0);
}

int		change_palette(int key, t_ptrs *p)
{
	key = 0;
	if (p->f->color == COLOR4)
		p->f->color = PINK;
	else if (p->f->color == PINK)
		p->f->color = L_RED;
	else if (p->f->color == L_RED)
		p->f->color = L_BLUE;
	else if (p->f->color == L_BLUE)
		p->f->color = RASPBERRY;
	else if (p->f->color == RASPBERRY)
		p->f->color = RED;
	else if (p->f->color == RED)
		p->f->color = GREEN;
	else
		p->f->color = COLOR4;
	fill_palette(p->f);
	launch_threads(p);
	return (0);
}
