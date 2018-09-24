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
# include <math.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include "../libft/includes/libft.h"
# define WIDTH 1800
# define HEIGHT 1100
# define CENTER_W (WIDTH / 2.0)
# define CENTER_H (HEIGHT / 2.0)
# define GREY_BLUE 0x667793
# define PINK 0xe7a0ff
# define L_RED 0xdb7891
# define L_BLUE 0x8acbd1
# define D_BLUE 0x12345a
# define GREEN 0x5da058
# define RED 0xfc1500
# define RASPBERRY 0x7f0347
# define WHITE 0xffffff
# define BLACK 0x000000
# define PALETTE_SIZE 2048
# define COLOR1 0x010542
# define COLOR2 0x27558e
# define COLOR3 0xedffff
# define COLOR4 0xffaa00
# define COLOR5 0x000200
# define THREADS_NUM 4

typedef struct		s_copmlex
{
	double			re;
	double			im;
}					t_complex;

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
	t_dot			*pos;
}					t_mouse;

typedef struct		s_f
{
	int				color;
	char			fract;
	int				iter;
	t_complex		j_c;
	double			zoom;
	t_dot			shift;
	int				palette[PALETTE_SIZE];
}					t_f;

typedef struct		s_ptrs
{
	void			*win_ptr;
	void			*mlx_ptr;
	void			*img_ptr;
	int				*img;
	t_f				*f;
}					t_ptrs;

typedef struct		s_threads
{
	t_ptrs			*p;
	pthread_t		threads;
	unsigned		num;
}					t_threads;

void				*draw_fract(void *p);
/*
**		KEYS
*/
int					deal_keys(int key, t_ptrs *f);
int					mouse_press(int button, int x, int y, t_ptrs *p);
int					mouse_release(int button, int x, int y, t_ptrs *f);
int					mouse_move(int x, int y, t_ptrs *f);
int					shifting(int key, t_ptrs *p);
int					zooming(int key, t_ptrs *p);
int					change_palette(int key, t_ptrs *p);

/*
**		COLORS
*/
void				fill_palette(t_f *f);

/*
**		COMPLEX
*/
t_complex			mul(t_complex c1, t_complex c2);
t_complex			add(t_complex c1, t_complex c2);
t_complex			sub(t_complex c1, t_complex c2);
t_complex			sqr(t_complex c);
double				mod(t_complex a);
/*
**		addtitional
*/
void				put_pixel_to_image(t_ptrs *p, int x, int y, int color);
void				set_dotd(t_dotd *a, double x, double y);
void				set_dot(t_dot *a, int x, int y);
void				launch_threads(t_ptrs *p);
void				clear_all(t_ptrs *p);

#endif
