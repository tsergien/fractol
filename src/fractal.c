/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:40:00 by tsergien          #+#    #+#             */
/*   Updated: 2018/09/13 11:40:01 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		julia(t_ptrs *p, int x, int y)
{
	int			i;
	t_complex	z0;
	t_complex	z1;
	double		smooth;

	i = 0;
	z0.re = 1.5 * (x + p->f->shift.x - CENTER_W) / (0.5 * p->f->zoom * WIDTH);
	z0.im = (y + p->f->shift.y - CENTER_H) / (0.5 * p->f->zoom * HEIGHT);
	while (++i <= p->f->iter)
	{
		z1 = add(sqr(z0), p->f->j_c);
		if (mod(z1) > 2.0)
		{
			smooth = log(log(mod(z1)) / M_LOG2E) / M_LOG2E;
			p->img[x + WIDTH * y] = p->f->palette[(int)(sqrt(i + 1 - smooth)
			* 256) % PALETTE_SIZE];
			break ;
		}
		z0 = z1;
	}
	if (i > p->f->iter)
		p->img[x + y * WIDTH] = 0;
}

static void		mandelbrot(t_ptrs *p, int x, int y)
{
	t_complex	pix;
	t_complex	z;
	int			iter;
	double		temp;

	iter = -1;
	z.re = 0;
	z.im = 0;
	pix.re = 1.5 * (x + p->f->shift.x - CENTER_W) / (p->f->zoom * CENTER_W) - 1;
	pix.im = (y + p->f->shift.y - CENTER_H) / (p->f->zoom * CENTER_H);
	while (z.re * z.re + z.im * z.im < 4.0 && ++iter < p->f->iter)
	{
		temp = z.re * z.re - z.im * z.im + pix.re;
		z.im = 2 * z.re * z.im + pix.im;
		z.re = temp;
	}
	temp = log(log(mod(z)) / M_LOG2E) / M_LOG2E;
	p->img[x + WIDTH * y] = p->f->palette[(int)(sqrt(iter + 1 - temp)
	* 256) % PALETTE_SIZE];
}

static void		manage(t_ptrs *p, double *x0, double *y0, int dice_throw)
{
	t_dotd		xy1;

	if (dice_throw == 0)
		set_dotd(&xy1, 0, 0.16 * *y0);
	else if (dice_throw >= 1 && dice_throw <= 7)
		set_dotd(&xy1, -0.15 * *x0 + 0.28 * *y0, 0.26 *
		*x0 + 0.24 * *y0 + 0.44);
	else if (dice_throw >= 8 && dice_throw <= 15)
		set_dotd(&xy1, 0.2 * *x0 - 0.26 * *y0, 0.23 * *x0 + 0.22 * *y0 + 1.6);
	else
		set_dotd(&xy1, 0.85 * *x0 + 0.04 * *y0, -0.04 * *x0 + 0.85 * *y0 + 1.6);
	*x0 = xy1.x * p->f->zoom * 100 - p->f->shift.x + CENTER_W;
	*y0 = p->f->zoom * 100 * xy1.y - p->f->shift.y;
	if (*x0 > -1 && *x0 < WIDTH && *y0 > -1 && *y0 < HEIGHT)
		p->img[(int)*x0 + WIDTH * (int)*y0] = GREEN;
	*x0 = xy1.x;
	*y0 = xy1.y;
}

static void		*barnsley_fern(t_ptrs *p, int x, int y)
{
	int			n;
	double		x0;
	double		y0;
	time_t		t;
	int			dice_throw;

	x0 = x;
	y0 = y;
	srand((unsigned)time(&t));
	n = 100000 * (p->f->zoom + 2) * (p->f->zoom + 2);
	while (n-- > 0)
	{
		dice_throw = rand() % 100;
		manage(p, &x0, &y0, dice_throw);
	}
	return (0);
}

void			*draw_fract(void *p)
{
	t_threads	*thread;
	int			i;
	int			j;
	int			max_y;
	void		(*fractal[3])(t_ptrs *, int, int);

	thread = (t_threads *)p;
	if (thread->p->f->fract == 2)
		return (barnsley_fern(thread->p, 0, 0));
	fractal[0] = mandelbrot;
	fractal[1] = julia;
	i = HEIGHT / 4 * thread->num - 1;
	max_y = HEIGHT / 4 * (thread->num + 1);
	while (++i < max_y)
	{
		j = -1;
		while (++j < WIDTH)
			fractal[(int)thread->p->f->fract](thread->p, j, i);
	}
	return (NULL);
}
