/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:57:59 by ikadimi           #+#    #+#             */
/*   Updated: 2019/11/10 16:31:45 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# define HEIGHT 600
# define WIDTH 600
# define ALT_X(x) (x /((double)WIDTH /(start->r_xf-start->r_xi)) +start->r_xi)
# define ALT_Y(y) (y /((double)HEIGHT /(start->r_yf-start->r_yi)) +start->r_yi)
# define Z_R (start->z_r * start->z_r - start->z_i * start->z_i + start->c_r)
# define Z_I (2 * start->t * start->z_i + start->c_i)
# define RED ((start->iteration * start->r) % 255)
# define GREEN ((start->iteration * start->g) % 255)
# define BLUE ((start->iteration * start->b) % 255)

typedef struct		s_init
{
	void			*init;
	void			*img;
	void			*win;
	char			*name;
	unsigned char	*img_str;
	double			x;
	double			y;
	double			t;
	double			r_xi;
	double			r_xf;
	double			r_yi;
	double			r_yf;
	double			z_r;
	double			z_i;
	double			c_r;
	double			c_i;
	int				iteration;
	int				zoom;
	int				iter_max;
	double			mo_x;
	double			mo_y;
	long			prev_x;
	long			prev_y;
	int				freez;
	int				r;
	int				g;
	int				b;
}					t_init;

void				ft_light_pixel(t_init *start, int r, int g, int b);
void				mandelbrot_fun(t_init *start);
void				julia_fun(t_init *start);
void				burning_ship_fun(t_init *start);
void				refresh_window(t_init *start);
void				init_prog(t_init *start);
int					mouse_press(int button, int x, int y, t_init *start);

#endif
