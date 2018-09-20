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

static void		manage(t_dot *pixel, t_ptrs *p)
{
	t_dotd		scaled;
	t_complex	z;
	int			iter;
	double		temp;

	iter = -1;
	z.re = 0;
	z.im = 0;
	scaled.x = p->f->zoom * ((double)(pixel->x + p->f->shift.x) * 3.5 / WIDTH - 2.5);
	scaled.y = p->f->zoom * ((double)(pixel->y + p->f->shift.y) * 2 / HEIGHT - 1);
	while (z.re * z.re + z.im * z.im < 4.0 && ++iter < p->f->iter)
	{
		temp = z.re * z.re - z.im * z.im + scaled.x;
		z.im = 2 * z.re * z.im + scaled.y;
		z.re = temp;
	}
	temp = log(log(mod(z)) / M_LOG2E) / M_LOG2E;
	put_pixel_to_image(p, pixel->x, pixel->y,
	p->f->palette[(int)(sqrt(iter + 1 - temp) * 256) % PALETTE_SIZE]);
}

static void		mandelbrot(t_ptrs *p)
{
	t_dot		pixel;

	pixel.x = -1;
	while (++pixel.x < WIDTH)
	{
		pixel.y = -1;
		while (++pixel.y < HEIGHT)
			manage(&pixel, p);
	}
}

void			draw_fract(t_ptrs *p)
{
	double			radius;
	
	radius = 2;
	clear_all(p);
	if (p->f->fract == 0)
		mandelbrot(p);
	if (p->f->fract == 1)
		julia(p, p->f->j_c, radius, p->f->iter);
	if (p->f->fract == 2)
		barnsleyFern(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
}