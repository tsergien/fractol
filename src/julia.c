/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:39:39 by tsergien          #+#    #+#             */
/*   Updated: 2018/09/13 11:39:41 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		manage(t_ptrs *p, t_dot *o, t_complex c, t_dotd rn)
{
	int			i;
	t_complex	z0;
	t_complex	z1;
	double		smooth;

	i = 0;
	z0.re = 1.5 * (o->x - CENTER_W) / (0.5 * p->f->zoom * WIDTH) + p->f->shift.x;
    z0.im = (o->y - CENTER_H) / (0.5 * p->f->zoom * HEIGHT) + p->f->shift.y;
	while (++i <= rn.y)
	{
		z1 = add(sqr(z0), c);
		if(mod(z1) > rn.x)
		{
			smooth = log(log(mod(z1)) / M_LOG2E) / M_LOG2E;
			put_pixel_to_image(p, o->x, o->y,
			p->f->palette[(int)(sqrt(i + 1 - smooth) * 256) % PALETTE_SIZE]);
			break ;
		}
		z0 = z1;
	}
	return (i);
}

void		julia(t_ptrs *p, t_complex c, double radius, int n)
{
	t_dot		o;
	int			i;
	t_dotd		rn;
	
	rn.x = radius;
	rn.y = (double)n;
	o.x = -1;
	while (++o.x < WIDTH)
	{
		o.y = -1;
		while (++o.y < HEIGHT)
		{
			i = manage(p, &o, c, rn);
			if (i > n)
				put_pixel_to_image(p, o.x, o.y, 0);
		}
	}
}