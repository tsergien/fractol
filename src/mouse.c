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

// double interpolate(double start, double end, double interpolation)
// {
//     return (start + ((end - start) * interpolation));
// }

// void applyZoom(t_ptrs *p, int mouseRe, int mouseIm)
// {
//      double interpolation;
	 
// 	 interpolation = 1.0 / p->f->zoom;
//     //  p->Re.min = interpolate((double)mouseRe, 0, interpolation);
//     //  p->Re.max = interpolate((double)mouseRe, WIDTH, interpolation);
//     //  p->Im.min = interpolate((double)mouseIm, 0, interpolation);
//     //  p->Im.max = interpolate((double)mouseIm, HEIGHT, interpolation);
// }

int		mouse_press(int button, int x, int y, t_ptrs *p)
{
	// double mouseRe = (double)x / (WIDTH / (p->Re.max - p->Re.min)) + p->Re.min;
	// double mouseIm = (double)y / (HEIGHT / (p->Im.max - p->Im.min)) + p->Im.min;
	
	// applyZoom(p, mouseRe, mouseIm);
	clear_all(p);
	if (button == 4)
		p->f->zoom += 0.05;
	else if (button == 5)
		p->f->zoom -= 0.05;
	if (p->f->fract == 0)
	{
		p->f->shift.x += x - CENTER_W;
		p->f->shift.y += y - CENTER_H;
	}
	draw_fract(p);
	return (0);
}

int		mouse_release(int button, int x, int y, t_ptrs *p)
{
	if (button == 1)
	{
		p->f->shift.x -= x - CENTER_W;
		p->f->shift.y -= y - CENTER_H;
	}
	return (0);
}

int		mouse_move(int x, int y, t_ptrs *p)
{
	if (p->f->fract == 1)
	{
		clear_all(p);
		p->f->j_c.re = (double)(x - CENTER_W) / WIDTH;
		p->f->j_c.im = (double)(y - CENTER_H) / HEIGHT;
		draw_fract(p);
	}
	(void)p;
	return (0);
}

