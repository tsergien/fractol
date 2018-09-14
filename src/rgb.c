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
