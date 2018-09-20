/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:17:50 by tsergien          #+#    #+#             */
/*   Updated: 2018/09/16 15:17:52 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		shifting(int key, t_ptrs *p)
{
	if (key == 126)
		p->f->shift.y -= 10;
	else if (key == 125)
		p->f->shift.y += 10;
	else if (key == 123)
		p->f->shift.x -= 10;
	else if (key == 124)
		p->f->shift.x += 10;
	clear_all(p);
	draw_fract(p);
	return (0);
}

int		zooming(int key, t_ptrs *p)
{
	if (key == 78)
		p->f->zoom += 0.05;
	else if (key == 69)
		p->f->zoom -= 0.05;
	clear_all(p);
	draw_fract(p);
	return (0);
}