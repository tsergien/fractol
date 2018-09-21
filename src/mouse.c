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

double interpolate(double start, double end, double interpolation)
{
    return (start + ((end - start) * interpolation));
}

void applyZoom(t_ptrs *p, int x, int y)
{
    double interpolation;
	 
	interpolation = 1.0 / p->f->zoom;
	// e->Re.min = interpolate(mouseRe, e->Re.min, interpolation);
    // e->Im.min = interpolate(mouseIm, e->Im.min, interpolation);
    // e->Re.max = interpolate(mouseRe, e->Re.max, interpolation);
    // e->Im.max = interpolate(mouseIm, e->Im.max, interpolation);
	x = y;
}

int		mouse_press(int button, int x, int y, t_ptrs *p)
{
	// double mouseRe = (double)x / (WIDTH / (p->Re.max - p->Re.min)) + p->Re.min;
	// double mouseIm = (double)y / (HEIGHT / (p->Im.max - p->Im.min)) + p->Im.min;
	
	// applyZoom(p, mouseRe, mouseIm);
	applyZoom(p, x, y);
	if (button == 4)
		p->f->zoom -= 0.05;
	else if (button == 5)
		p->f->zoom += 0.05;
		//shifting depends only from mouse loication, but not from the 
	if (p->f->fract != 1)
	{
		x = x / (WIDTH / 4);
		y = y / (HEIGHT / 4);
		p->f->shift.x += x < 2 ? 20 * (x%2 + 1) : -20 * (x%2 + 1);
		p->f->shift.y += y < 2 ? 20 * (y%2 + 1) : -20 * (y%2 + 1);
	}
	launch_threads(p);
	x = y;
	return (0);
}

int		mouse_release(int button, int x, int y, t_ptrs *p)
{
	if (button == 1)
	{
		p->f->shift.x += CENTER_W - x;
		p->f->shift.y += CENTER_H - y;
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

