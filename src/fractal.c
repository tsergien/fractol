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
		if(mod(z1) > 2.0)
		{
			smooth = log(log(mod(z1)) / M_LOG2E) / M_LOG2E;
			put_pixel_to_image(p, x, y,
			p->f->palette[(int)(sqrt(i + 1 - smooth) * 256) % PALETTE_SIZE]);
			break ;
		}
		z0 = z1;
	}
	if (i > p->f->iter)
		put_pixel_to_image(p, x, y, 0);
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
	pix.re = (1.0 / p->f->zoom * ((double)x) - p->f->shift.x) * 3.5 / WIDTH - 2.5;
	pix.im = (1.0 / p->f->zoom * ((double)y) - p->f->shift.y) * 2 / HEIGHT - 1;
	while (z.re * z.re + z.im * z.im < 4.0 && ++iter < p->f->iter)
	{
		temp = z.re * z.re - z.im * z.im + pix.re;
		z.im = 2 * z.re * z.im + pix.im;
		z.re = temp;
	}
	temp = log(log(mod(z)) / M_LOG2E) / M_LOG2E;
	put_pixel_to_image(p, x, y,
	p->f->palette[(int)(sqrt(iter + 1 - temp) * 256) % PALETTE_SIZE]);
}

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
	put_pixel_to_image(p, p->f->shift.x + p->f->zoom * 100 * x1 + CENTER_W,
	p->f->shift.y + p->f->zoom * 100 * y1, GREEN);
	*x0 = x1;
	*y0 = y1;
}

static void        *barnsley_fern(t_ptrs *p, int x, int y)
{
	int         n;
	double      x0;
	double      y0;
	time_t      t;
	int			diceThrow;

	x = y;
	x0 = 0;
	y0 = 0;
	srand((unsigned)time(&t));
	n = 100000 * p->f->zoom * 10;
	while(n-- > 0)
	{
		diceThrow = rand() % 100;
		manage(p, &x0, &y0, diceThrow);
	}
	return (NULL);
}

void			*draw_fract(void *p)
{
	t_threads	*thread;
	int			i;
	int			j;
	int			max_y;
	void		(*fractal[2])(t_ptrs *,  int , int);
	
	thread = (t_threads *)p;
	fractal[0] = mandelbrot;
	fractal[1] = julia;
	i = HEIGHT / 4 * thread->num - 1;
	max_y = HEIGHT / 4 * (thread->num + 1);
	if (thread->p->f->fract == 2)
		return (barnsley_fern(thread->p, 0, 0));
	while (++i < max_y)
	{
		j = -1;
		while (++j < WIDTH)
			fractal[(int)thread->p->f->fract](thread->p, j, i);
	}
	return (NULL);
}