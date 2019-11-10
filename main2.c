/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:56:07 by ikadimi           #+#    #+#             */
/*   Updated: 2019/11/10 16:49:58 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_light_pixel(t_init *start, int r, int g, int b)
{
	int i;

	if (start->x < 0 || start->y < 0 || start->x >= WIDTH || start->y >= HEIGHT)
		return ;
	i = start->x * 4 + WIDTH * 4 * start->y;
	start->img_str[i] = b;
	start->img_str[i + 1] = g;
	start->img_str[i + 2] = r;
}

void	init_prog(t_init *start)
{
	int b_p;
	int s_l;
	int endian;

	start->r = 21;
	start->g = 5;
	start->b = 17;
	start->r_xi = -2;
	start->r_xf = 2;
	start->r_yi = -2;
	start->r_yf = 2;
	start->iter_max = 50;
	start->mo_x = 0;
	start->mo_y = 0;
	start->prev_x = 1100;
	start->prev_y = 120;
	start->freez = 1;
	start->init = mlx_init();
	start->win = mlx_new_window(start->init, HEIGHT, WIDTH, start->name);
	start->img = mlx_new_image(start->init, HEIGHT, WIDTH);
	start->img_str = (unsigned char *)mlx_get_data_addr(start->img,
			&b_p, &s_l, &endian);
}

void	refresh_window(t_init *start)
{
	mlx_clear_window(start->init, start->win);
	mlx_destroy_image(start->init, start->img);
	start->img = mlx_new_image(start->init, HEIGHT, WIDTH);
	if (!ft_strcmp(start->name, "Mandelbrot"))
		mandelbrot_fun(start);
	else if (!ft_strcmp(start->name, "Julia"))
		julia_fun(start);
	else if (!ft_strcmp(start->name, "Burning"))
		burning_ship_fun(start);
}

double	return_pow(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

int		mouse_press(int button, int x, int y, t_init *start)
{
	if (button == 4)
	{
		start->iter_max += 1;
		start->r_xi = return_pow(ALT_X(x), start->r_xi, 0.9 / 1.01);
		start->r_xf = return_pow(ALT_X(x), start->r_xf, 0.9 / 1.01);
		start->r_yi = return_pow(ALT_Y(y), start->r_yi, 0.9 / 1.01);
		start->r_yf = return_pow(ALT_Y(y), start->r_yf, 0.9 / 1.01);
	}
	else if (button == 5 && fabs(start->r_xf - start->r_xi) <= 5)
	{
		if (start->iter_max >= 70)
			start->iter_max -= 1;
		start->r_xi = return_pow(ALT_X(x), start->r_xi, 1.01 / 0.9);
		start->r_xf = return_pow(ALT_X(x), start->r_xf, 1.01 / 0.9);
		start->r_yi = return_pow(ALT_Y(y), start->r_yi, 1.01 / 0.9);
		start->r_yf = return_pow(ALT_Y(y), start->r_yf, 1.01 / 0.9);
	}
	refresh_window(start);
	return (1);
}
