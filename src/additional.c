/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:36:08 by tsergien          #+#    #+#             */
/*   Updated: 2018/09/14 15:36:09 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			put_pixel_to_image(t_ptrs *p, int x, int y, int color)
{
	if (x > -1 && y > -1 && x < WIDTH && y <HEIGHT)
		p->img[x + y *WIDTH] = color;
}

void			set_dotd(t_dotd *a, double x, double y)
{
	a->x = x;
	a->y = y;
}

void			set_dot(t_dot *a, int x, int y)
{
	a->x = x;
	a->y = y;
}

void			clear_all(t_ptrs *p)
{
	int		i;

	i = -1;
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	while (++i < WIDTH * HEIGHT)
		p->img[i] = 0;
}
