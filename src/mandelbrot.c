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

static int		palette(int iter, int color)
{
	int		color_temp;
	double	c;
	
	color_temp = color;
	c = (double)iter / 10;
	darken(&color_temp, c);
	return (color_temp);
}

static void		manage(t_dot *pixel, t_ptrs *p)
{
	t_dotd		scaled;
	t_dotd		it;
	int			iter;
	int			max_it;
	double		temp;

	iter = -1;
	max_it = 1000;
	set_dotd(&it, 0, 0);
	set_dotd(&scaled, ((double)pixel->x / WIDTH) * 3.5 - 2.5,
	((double)pixel->y * 2 / HEIGHT - 1));
	while (it.x * it.x + it.y * it.y < 4 && ++iter < max_it)
	{
		temp = it.x * it.x - it.y * it.y + scaled.x;
		it.y = 2 * it.x * it.y + scaled.y;
		it.x = temp;
	}
	put_pixel_to_image(p, pixel->x, pixel->y, palette(iter, p->f->color));
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
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
}

void			draw_fract(t_ptrs *p)
{
	if (p->f->fract == 0)
		mandelbrot(p);
	// if (p->f->fract == 1)
	// 	julia(p);
}