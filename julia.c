/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:54:19 by ikadimi           #+#    #+#             */
/*   Updated: 2019/11/10 15:56:34 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_two(t_init *start)
{
	start->c_r = start->mo_x;
	start->c_i = start->mo_y;
	start->z_r = ALT_X(start->x);
	start->z_i = ALT_Y(start->y);
	start->iteration = 0;
	while (start->iteration < start->iter_max &&
			((start->z_r * start->z_r) + (start->z_i * start->z_i)) < 4)
	{
		start->t = start->z_r;
		start->z_r = Z_R;
		start->z_i = Z_I;
		start->iteration++;
	}
	if (start->iteration == start->iter_max)
		ft_light_pixel(start, 0, 0, 0);
	else
		ft_light_pixel(start, RED, GREEN, BLUE);
	start->x++;
}

void	julia_fun(t_init *start)
{
	start->y = 0;
	while (start->y < HEIGHT)
	{
		start->x = 0;
		while (start->x < WIDTH)
			julia_two(start);
		start->y++;
	}
	mlx_put_image_to_window(start->init, start->win, start->img, 0, 0);
}
