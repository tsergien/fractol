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

static t_ptrs			*init_ptr(void)
{
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	t_ptrs			*p;

	bits_per_pixel = 32;
	size_line = WIDTH;
	endian = 1;
	p = (t_ptrs *)malloc(sizeof(t_ptrs));
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, WIDTH, HEIGHT, "FRACTOL");
	p->img_ptr = mlx_new_image(p->mlx_ptr, WIDTH, HEIGHT);
	p->img = (int *)mlx_get_data_addr(p->img_ptr, &bits_per_pixel,
			&size_line, &endian);
	p->f = (t_f *)malloc(sizeof(t_f));
	p->f->color = GREY_BLUE;
	p->f->fract = 0;
	return (p);
}

int						main(void)
{
	t_ptrs		*p;

	p = init_ptr();
	draw_fract(p);

	mlx_hook(p->win_ptr, 4, 1L << 2, mouse_press, p);
	mlx_hook(p->win_ptr, 5, 1L << 3, mouse_release, p);
	mlx_hook(p->win_ptr, 6, 1L << 13, mouse_move, p);
	mlx_hook(p->win_ptr, 2, 1L << 0, deal_keys, p);
	mlx_hook(p->win_ptr, 17, 1L << 17, exit_x, p);
	mlx_loop(p->mlx_ptr);
	return (0);
}
