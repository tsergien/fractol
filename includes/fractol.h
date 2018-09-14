/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 10:25:50 by tsergien          #+#    #+#             */
/*   Updated: 2018/09/13 10:35:38 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# define WIDTH 1800
# define HEIGHT 1100
# define GREY_BLUE 0x667793
# define PINK 0xe7a0ff
# define L_RED 0xdb7891
# define L_BLUE 0x8acbd1
# define D_BLUE 0x12345a
# define GREEN 0x5da058
# define ORANGE 0xfc9f00
# define RED 0xfc1500
# define RASPBERRY 0x7f0347
# define WHITE 0xffffff
# define BLACK 0x000000

#include <stdio.h>

typedef struct		s_dot
{
	int				x;
	int				y;
}					t_dot;

typedef struct		s_dotd
{
	double			x;
	double			y;
}					t_dotd;

typedef struct		s_mouse
{
	char			press;
	t_dot			pos;
}					t_mouse;

/*
**		fract: 0-mandelbrot, 1-julia, 2-third
*/
typedef struct		s_f
{
	int				color;
	t_mouse			mouse;
	char			fract;
}					t_f;

typedef struct		s_ptrs
{
	void			*win_ptr;
	void			*mlx_ptr;
	void			*img_ptr;
	int				*img;
	t_f				*f;
}					t_ptrs;

typedef struct		s_copmlex
{
	int				re;
	int				im;
}					t_complex;


void				draw_fract(t_ptrs *p);

/*
**		KEYS
*/
int					deal_keys(int key, t_ptrs *f);
int					mouse_press(int button, int x, int y, t_ptrs *p);
int					mouse_release(int button, int x, int y, t_ptrs *f);
int					mouse_move(int x, int y, t_ptrs *f);

/*
**		COLORS
*/
void				darken(int *col, double c);

/*
**		COMPLEX
*/
t_complex			mul(t_complex c1, t_complex c2);
t_complex			add(t_complex c1, t_complex c2);
t_complex			sub(t_complex c1, t_complex c2);
/*
**		addtitional
*/
void				put_pixel_to_image(t_ptrs *p, int x, int y, int color);
void				set_dotd(t_dotd *a, double x, double y);
void				set_dot(t_dot *a, int x, int y);
void				clear_all(t_ptrs *p);

#endif
