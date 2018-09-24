/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:37:39 by tsergien          #+#    #+#             */
/*   Updated: 2018/09/13 11:37:40 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**		Mouse button codes
**		Left button — 1
**		Right button —  2
**		Third (Middle) button — 3
**		Scroll Up — 4
**		Scroll Down — 5
**		Scroll Left — 6
**		Scroll Right — 7
*/

int		mouse_press(int button, int x, int y, t_ptrs *p)
{
	if (button == 4)
		p->f->zoom -= 0.05;
	else if (button == 5)
		p->f->zoom += 0.05;
	launch_threads(p);
	x = y;
	return (0);
}

int		mouse_release(int button, int x, int y, t_ptrs *p)
{
	if (button == 1)
	{
		p->f->shift.x -= CENTER_W - x;
		p->f->shift.y -= CENTER_H - y;
	}
	launch_threads(p);
	return (0);
}

int		mouse_move(int x, int y, t_ptrs *p)
{
	if (p->f->fract == 1)
	{
		p->f->j_c.re = (double)(x - CENTER_W) / WIDTH;
		p->f->j_c.im = (double)(y - CENTER_H) / HEIGHT;
		launch_threads(p);
	}
	(void)p;
	return (0);
}
