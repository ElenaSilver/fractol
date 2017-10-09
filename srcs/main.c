/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:51:24 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/09 06:08:19 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_pixel(t_fractol *env, int x, int y, int i)
{
	int		k;
	int		c[7];

	k = (x * 4) + (y * env->sline);
	c[0] = 0xFF00FF;
	c[1] = 0xFF0000;
	c[2] = 0x00FF00;
	c[3] = 0xFFFF00;
	c[4] = 0x0000FF;
	c[5] = 0x00FFFF;
	c[6] = 0xFFFFFF;
	if (!(x > WIDTH - 1 || x < 0 || y > HEIGHT - 1 || y < 0))
	{
		if (i == env->it_max)
		{
			env->data[k] = 0;
			env->data[++k] = 0;
		}
		else
		{
			env->data[k] = (i * ((c[env->c % 7] >> 16) & 0xFF)) / env->it_max;
			env->data[++k] = (i * ((c[env->c % 7] >> 8) & 0xFF)) / env->it_max;
			env->data[++k] = (i * ((c[env->c % 7]) & 0xFF)) / env->it_max;
		}
	}
}

int			ft_image_put(t_fractol *env)
{
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->data = mlx_get_data_addr(env->img, &env->bpp,
	&env->sline, &env->endian);
	ft_print(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	display_usage(env);
	return (0);
}

int			main(int argc, char **argv)
{
	t_fractol	*env;

	if (!(env = (t_fractol*)malloc(sizeof(t_fractol))))
		return (1);
	if (!ft_checker(argv, argc, env))
		return (1);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "eserebry fractol");
	env->it_max = 100;
	env->c = 100;
	env->zoom = 1;
	env->lock = 0;
	mlx_hook(env->win, 6, 0, ft_mousemove, env);
	mlx_expose_hook(env->win, ft_image_put, env);
	mlx_mouse_hook(env->win, ft_mouse_key, env);
	mlx_key_hook(env->win, ft_key, env);
	mlx_loop_hook(env->mlx, ft_image_put, env);
	mlx_loop(env->mlx);
	return (0);
}
