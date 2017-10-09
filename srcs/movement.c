/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:15:30 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/09 06:05:13 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	reset(t_fractol *env)
{
	env->real = 0.0;
	env->imag = 0.0;
	env->zoom = 1.0;
	env->mx = (env->fractal == 2 || env->fractal == 3) ? -100.0 : 0.0;
	env->my = (env->fractal == 3) ? 100.0 : 0.0;
	env->it_max = 15;
}

static int	ft_color(int keycode, t_fractol *env)
{
	int		x;
	int		y;
	int		i;

	(keycode == 8 && env->c < 9999999) ? env->c *= 10 : 0;
	(keycode == 7 && env->c > 3) ? env->c /= 10 : 0;
	draw_pixel(env, x, y, i);
	return (0);
}

int			ft_key(int keycode, t_fractol *env)
{
	(keycode == 53) ? exit(0) : 0;
	(keycode == 69) ? env->zoom *= 1.1 : 0;
	(keycode == 78) ? env->zoom /= 1.1 : 0;
	(keycode == 126) ? env->my -= 50.0 : 0;
	(keycode == 125) ? env->my += 50.0 : 0;
	(keycode == 123) ? env->mx += 50.0 : 0;
	(keycode == 124) ? env->mx -= 50.0 : 0;
	(keycode == 258) ? env->it_max += 10 : 0;
	(keycode == 269 && env->it_max > 10) ? env->it_max -= 20 : 0;
	if (keycode == 49)
		reset(env);
	else if (keycode == 45)
	{
		env->fractal++;
		(env->fractal > 4) ? env->fractal = 1 : 0;
		reset(env);
	}
	(keycode == 53) ? exit(0) : 0;
	ft_color(keycode, env);
	return (0);
}

int			ft_mousemove(int x, int y, t_fractol *env)
{
	int		i;

	if ((x == env->real && y == env->imag) || env->lock == 1)
		return (0);
	env->real = ((((double)x - WIDTH) / (WIDTH / 2)) + 1);
	env->imag = ((((double)y - HEIGHT) / (HEIGHT / 2)) + 1);
	draw_pixel(env, x, y, i);
	return (1);
}

int			ft_mouse_key(int key, int x, int y, t_fractol *env)
{
	double	movex1;
	double	movey1;

	movex1 = (4.0) / (double)(WIDTH - 1);
	movey1 = (4.0) / (double)(HEIGHT - 1);
	if (key == 4)
	{
		env->mx = ((-2.0 + (x + env->mx) * movex1)
				* 1.2 + 2.0 - x * movex1) / movex1;
		env->my = -((-2.0 + (y - env->my) * movey1)
				* 1.2 + 2.0 - y * movey1) / movey1;
		env->zoom *= 1.1;
	}
	else if (key == 5)
	{
		env->mx = ((-2.0 + (x + env->mx) * movex1)
				* (1 / 1.2) + 2.0 - x * movex1) / movex1;
		env->my = -((-2.0 + (y - env->my) * movey1)
				* (1 / 1.2) + 2.0 - y * movey1) / movey1;
		env->zoom /= 1.1;
	}
	(key == 1) ? env->it_max += 10 : 0;
	(key == 2) ? env->c *= 10 : 0;
	return (0);
}
