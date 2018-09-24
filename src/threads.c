/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:58:53 by tsergien          #+#    #+#             */
/*   Updated: 2018/09/21 10:58:55 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			launch_threads(t_ptrs *p)
{
	t_threads	t[THREADS_NUM];
	int			i;

	i = -1;
	clear_all(p);
	while (++i < THREADS_NUM)
	{
		t[i].p = p;
		t[i].num = i;
		pthread_create(&t[i].threads, NULL, draw_fract, &t[i]);
	}
	i = -1;
	while (++i < THREADS_NUM)
		pthread_join(t[i].threads, NULL);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
}
