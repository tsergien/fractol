/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:18:25 by tsergien          #+#    #+#             */
/*   Updated: 2018/09/12 19:18:27 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int				exit_x(int key, t_ptrs *p)
{
	(void)key;
	(void)p;
	exit(0);
	return (0);
}

static t_f				*init_f(void)
{
	t_f				*f;

	f = (t_f *)malloc(sizeof(t_f));
	f->iter = 100;
	f->j_c.re = -0.4;
	f->j_c.im = 0.6;
	f->zoom = 1;
	set_dot(&f->shift, 0, 0);
	f->color = COLOR4;
	fill_palette(f);
	return (f);
}

static t_ptrs			*init_ptr(void)
{
	int				b;
	int				s;
	int				e;
	t_ptrs			*p;

	b = 32;
	s = WIDTH;
	e = 1;
	p = (t_ptrs *)malloc(sizeof(t_ptrs));
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, WIDTH, HEIGHT, "FRACTOL");
	p->img_ptr = mlx_new_image(p->mlx_ptr, WIDTH, HEIGHT);
	p->img = (int *)mlx_get_data_addr(p->img_ptr, &b, &s, &e);
	p->f = init_f();
	return (p);
}

static int				usage(void)
{
	write(1, "usage: ./fractol [mandelbrot][julia][fern]\n", 43);
	return (0);
}

int						main(int argc, char **argv)
{
	t_ptrs		*p;
	int			i;

	i = 0;
	if (argc != 2)
		return (usage());
	p = init_ptr();
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		p->f->fract = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		p->f->fract = 1;
	else if (ft_strcmp(argv[1], "fern") == 0)
		p->f->fract = 2;
	else
		return (usage());
	launch_threads(p);
	mlx_hook(p->win_ptr, 4, 1L << 2, mouse_press, p);
	mlx_hook(p->win_ptr, 5, 1L << 3, mouse_release, p);
	mlx_hook(p->win_ptr, 6, 1L << 13, mouse_move, p);
	mlx_hook(p->win_ptr, 2, 1L << 0, deal_keys, p);
	mlx_hook(p->win_ptr, 17, 1L << 17, exit_x, p);
	mlx_loop(p->mlx_ptr);
	return (0);
}
