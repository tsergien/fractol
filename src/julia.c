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

static t_complex	map_point(double radius, int x, int y)
{
	t_complex	c;
	int			l;

	l = (WIDTH < HEIGHT) ? WIDTH : HEIGHT;
	c.re = 2 * radius * (x - WIDTH / 2.0) / l;
	c.im = 2 * radius * (y - HEIGHT / 2.0) / l ;
	return (c);
}

static int		j_palette(int iter, int color)
{
	int		color_temp;
	double	c;
	
	color_temp = color;
	c = (double)iter / 5;
	darken(&color_temp, c);
	return (color_temp);
}

static int		manage(t_ptrs *p, t_dot *o, t_complex c, t_dotd rn)
{
	int			i;
	t_complex	z0;
	t_complex	z1;

	i = 0;
	z0 = map_point(rn.x, o->x, o->y);
	while (++i <= rn.y)
	{
		z1 = add(sqr(z0), c);
		if(mod(z1) > rn.x)
		{
			put_pixel_to_image(p, o->x , o->y, j_palette(i % 15 + 1, p->f->color));
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