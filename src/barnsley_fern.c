/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley_fern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:49:52 by tsergien          #+#    #+#             */
/*   Updated: 2018/09/20 11:49:57 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	manage(t_ptrs *p, double *x0, double *y0, int diceThrow)
{
	double      x1;
	double      y1;

	x1 = 0;
	if(diceThrow == 0)
		y1 = 0.16 * *y0;
	else if(diceThrow >= 1 && diceThrow <= 7)
	{
		x1 = -0.15 * *x0 + 0.28 * *y0;
		y1 = 0.26 * *x0 + 0.24 * *y0 + 0.44;
	}
	else if(diceThrow >= 8 && diceThrow <= 15)
	{
		x1 = 0.2 * *x0 - 0.26 * *y0;
		y1 = 0.23 * *x0 + 0.22 * *y0 + 1.6;
	}
	else
	{
		x1 = 0.85 * *x0 + 0.04 * *y0;
		y1 = -0.04 * *x0 + 0.85 * *y0 + 1.6;
	}
	put_pixel_to_image(p, p->f->shift.x + p->f->zoom * 50 * x1 + CENTER_W,
	p->f->shift.y + p->f->zoom * 50 * y1, GREEN);
	*x0 = x1;
	*y0 = y1;
}

void        barnsleyFern(t_ptrs *p)
{
	int         i;
	double      x0;
	double      y0;
	time_t      t;
	int			diceThrow;

	x0 = 0;
	y0 = 0;
	srand((unsigned)time(&t));
	i = -1;
	while(++i < p->f->iter * 10000 * p->f->zoom * p->f->zoom)
	{
		diceThrow = rand() % 100;
		manage(p, &x0, &y0, diceThrow);
	}
}