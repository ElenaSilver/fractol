/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:15:28 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/09 05:51:56 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	julia(t_fractol *env, int x, int y)
{
	t_draw	draw;
	int		i;

	i = 0;
	draw.r2 = (-2.0 + (x + env->mx) * (4.0 / (double)(WIDTH - 1))) / env->zoom;
	draw.i2 = (-2.0 + (y - env->my) * (4.0 / (double)(HEIGHT - 1))) / env->zoom;
	while (draw.r2 * draw.r2 + draw.i2 * draw.i2 <= 4.0
			&& i < env->it_max)
	{
		draw.temp = draw.i2;
		draw.i2 = 2 * draw.r2 * draw.i2 + env->imag;
		draw.r2 = draw.r2 * draw.r2 - draw.temp * draw.temp + env->real;
		i++;
	}
	return (i);
}

static int	mandelbrot(t_fractol *env, int x, int y)
{
	t_draw	draw;
	int		i;

	i = 0;
	draw.r1 = (-2.0 + (x + env->mx) * (4.0 / (double)(WIDTH - 1))) / env->zoom;
	draw.i1 = (-2.0 + (y - env->my) * (4.0 / (double)(HEIGHT - 1))) / env->zoom;
	draw.r2 = draw.r1;
	draw.i2 = draw.i1;
	while (draw.r2 * draw.r2 + draw.i2 * draw.i2 <= 4.0
			&& i < env->it_max)
	{
		draw.temp = draw.i2;
		draw.i2 = 2 * draw.r2 * draw.i2 + draw.i1;
		draw.r2 = draw.r2 * draw.r2 - draw.temp * draw.temp + draw.r1;
		i++;
	}
	return (i);
}

static int	burning_ship(t_fractol *env, int x, int y)
{
	t_draw	draw;
	int		i;

	i = 0;
	draw.r1 = (-2.0 + (x + env->mx) * (4.0 / (double)(WIDTH - 1))) / env->zoom;
	draw.i1 = (-2.0 + (y - env->my) * (4.0 / (double)(HEIGHT - 1))) / env->zoom;
	draw.r2 = draw.r1;
	draw.i2 = draw.i1;
	while (draw.r2 * draw.r2 + draw.i2 * draw.i2 <= 4.0
			&& i < env->it_max)
	{
		draw.temp = draw.i2;
		draw.i2 = 2 * fabs(draw.r2 * draw.i2) + draw.i1;
		draw.r2 = draw.r2 * draw.r2 - draw.temp * draw.temp + draw.r1;
		i++;
	}
	return (i);
}

static int	spiral(t_fractol *env, int x, int y)
{
	t_draw	draw;
	int		i;

	i = 0;
	draw.r2 = (-2.0 + (x + env->mx) * (4.0 / (double)(WIDTH - 1))) / env->zoom;
	draw.i2 = (-2.0 + (y - env->my) * (4.0 / (double)(HEIGHT - 1))) / env->zoom;
	while (draw.r2 * draw.r2 + draw.i2 * draw.i2 <= 4.0
			&& i < env->it_max)
	{
		draw.temp = draw.i2;
		draw.i2 = 2 * fabs(draw.r2 * draw.i2) + env->imag;
		draw.r2 = draw.r2 * draw.r2 * draw.r2 * draw.r2
				- draw.temp * draw.temp + env->real;
		i++;
	}
	return (i);
}

void		ft_print(t_fractol *env)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	while (x < WIDTH - 1)
	{
		y = 0;
		while (y < HEIGHT - 1)
		{
			if (env->fractal == 1)
				i = julia(env, x, y);
			else if (env->fractal == 2)
				i = mandelbrot(env, x, y);
			else if (env->fractal == 3)
				i = burning_ship(env, x, y);
			else if (env->fractal == 4)
				i = spiral(env, x, y);
			draw_pixel(env, x, y, i);
			y++;
		}
		x++;
	}
}
