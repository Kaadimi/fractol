/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:38:06 by ikadimi           #+#    #+#             */
/*   Updated: 2019/11/10 16:48:22 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_init *start)
{
	if (!ft_strcmp(start->name, "Julia") && start->freez == 1)
	{
		mlx_clear_window(start->init, start->win);
		mlx_destroy_image(start->init, start->img);
		start->img = mlx_new_image(start->init, HEIGHT, WIDTH);
		if (start->prev_x < x && start->mo_x <= 1.95)
			start->mo_x += (0.05 * fabs(start->r_xf - start->r_xi) / 4);
		else if (start->prev_x > x && start->mo_x >= -1.95)
			start->mo_x -= (0.05 * fabs(start->r_xf - start->r_xi) / 4);
		if (start->prev_y < y && start->mo_y <= 1.95)
			start->mo_y += (0.05 * fabs(start->r_yf - start->r_yi) / 4);
		else if (start->prev_y > y && start->mo_y >= -1.95)
			start->mo_y -= (0.05 * fabs(start->r_yf - start->r_yi) / 4);
		start->prev_x = x;
		start->prev_y = y;
		julia_fun(start);
	}
	return (1);
}

void	key_press2(int button, t_init *start)
{
	if (button == 124)
	{
		start->r_xf += (0.1 * fabs(start->r_xf - start->r_xi) / 4);
		start->r_xi += (0.1 * fabs(start->r_xf - start->r_xi) / 4);
	}
	else if (button == 123)
	{
		start->r_xf -= (0.1 * fabs(start->r_xf - start->r_xi) / 4);
		start->r_xi -= (0.1 * fabs(start->r_xf - start->r_xi) / 4);
	}
	else if (button == 126)
	{
		start->r_yf -= (0.1 * fabs(start->r_yf - start->r_yi) / 4);
		start->r_yi -= (0.1 * fabs(start->r_yf - start->r_yi) / 4);
	}
	else if (button == 125)
	{
		start->r_yf += (0.1 * fabs(start->r_yf - start->r_yi) / 4);
		start->r_yi += (0.1 * fabs(start->r_yf - start->r_yi) / 4);
	}
}

int		key_press(int button, t_init *start)
{
	key_press2(button, start);
	if (button == 116)
		mouse_press(4, 300, 300, start);
	else if (button == 121)
		mouse_press(5, 300, 300, start);
	else if (button == 53)
	{
		mlx_destroy_image(start->init, start->img);
		exit(0);
	}
	else if (button == 49)
	{
		start->r = rand() % 50;
		start->g = rand() % 50;
		start->b = rand() % 255;
	}
	else if (button == 3)
		start->freez *= -1;
	if (button == 49 || button == 126 || button == 125
			|| button == 124 || button == 123)
		refresh_window(start);
	return (1);
}

int		main(int ac, char **av)
{
	t_init start;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Mandelbrot") &&
				ft_strcmp(av[1], "Julia") && ft_strcmp(av[1], "Burning"))
		{
			ft_putstr("Availble sets: Mandelbrot || Julia || Burning\n");
			return (0);
		}
		start.name = av[1];
		init_prog(&start);
		if (!ft_strcmp(av[1], "Mandelbrot"))
			mandelbrot_fun(&start);
		else if (!ft_strcmp(av[1], "Julia"))
			julia_fun(&start);
		else if (!ft_strcmp(av[1], "Burning"))
			burning_ship_fun(&start);
		mlx_hook(start.win, 2, 0, key_press, &start);
		mlx_hook(start.win, 4, 0, mouse_press, &start);
		mlx_hook(start.win, 6, 0, mouse_move, &start);
		mlx_loop(start.init);
	}
	else
		ft_putstr("usage: ./fractol Mandelbrot || Julia || Burning\n");
}
