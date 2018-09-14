/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:54:22 by tsergien          #+#    #+#             */
/*   Updated: 2018/09/13 12:59:01 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	add(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.im = c1.im + c2.im;
	res.re = c1.re + c2.re;
	return (res);
}

t_complex	sub(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.im = c1.im - c2.im;
	res.re = c1.re - c2.re;
	return (res);
}

t_complex	mul(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.im = c1.im * c2.re + c1.re * c2.im;
	res.re = c1.re * c2.re - c1.im * c2.im;
	return (res);
}


