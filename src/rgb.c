/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:35:08 by tsergien          #+#    #+#             */
/*   Updated: 2018/09/13 11:35:27 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			darken(int *col, double c)
{
	int		r_comp;
	int		g_comp;
	int		b_comp;
	int		key_factor;

	key_factor = (double)c * 100;
	r_comp = *col >> 16;
	g_comp = (*col & 0xff00) >> 8;
	b_comp = *col & 0xff;
	r_comp = (r_comp - r_comp * key_factor / 0x100) << 16;
	g_comp = (g_comp - g_comp * key_factor / 0x100) << 8;
	b_comp = b_comp - b_comp * key_factor / 0x100;
	*col = r_comp + g_comp + b_comp;
}

int				gradient(int color1, int color2, double k)
{
	int		r_comp;
	int		g_comp;
	int		b_comp;
	int		res;

	r_comp = k * (color1 >> 16) + (1 - k) * (color2 >> 16);
	g_comp = k * ((color1 & 0xff00) >> 8) + (1 - k) * ((color2 & 0xff00) >> 8);
	b_comp = k * (color1 & 0xff) + (1 - k) * (color2 & 0xff);
	res = (r_comp << 16) + (g_comp << 8) + b_comp;
	return (res);
}

void			fill_palette(t_f *f)
{
	int			j;
	int			colors[5];
	int			step;
	int			k;

	k = 0;
	j = -1;
	step = PALETTE_SIZE / 4;
	colors[0] = COLOR1;
	colors[1] = COLOR2;
	colors[2] = COLOR3;
	colors[3] = COLOR4;
	colors[4] = COLOR5;
	while (++j < PALETTE_SIZE)
	{
		if (j == step  || j == PALETTE_SIZE / 2 ||
		j == PALETTE_SIZE * 3 / 4)
			k++;
		f->palette[j] = gradient(colors[k + 1], colors[k], (double)(j % step) * 4.0 / PALETTE_SIZE);
	}
}