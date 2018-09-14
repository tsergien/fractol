/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:37:39 by tsergien          #+#    #+#             */
/*   Updated: 2018/09/13 11:37:40 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**		Mouse button codes
**		Left button — 1
**		Right button —  2
**		Third (Middle) button — 3
**		Scroll Up — 4
**		Scroll Down — 5
**		Scroll Left — 6
**		Scroll Right — 7
*/

int		mouse_press(int button, int x, int y, t_ptrs *p)
{
	x = y;
	(void)p;
	(void)button;
	// if (button == 4)
	// 	zooming(24, f);
	// else if (button == 5)
	// 	zooming(27, f);
	
	return (0);
}

int		mouse_release(int button, int x, int y, t_ptrs *f)
{
	x = y;
	(void)button;
	(void)f;
	return (0);
}

int		mouse_move(int x, int y, t_ptrs *f)
{
	x = y;
	(void)f;
	return (0);
}

