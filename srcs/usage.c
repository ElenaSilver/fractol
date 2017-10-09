/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:52:26 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/09 06:12:54 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage(void)
{
	ft_putendl("usage: ./fractol [fractal's name OR first letter]");
	ft_putendl("==========================");
	ft_putendl("fractal:	julia		: j");
	ft_putendl("		mandelbrot	: m");
	ft_putendl("		burningship	: b");
	ft_putendl("		spiral		: s");
}

static void	display_name(t_fractol *env)
{
	if (env->fractal == 1)
		mlx_string_put(env->mlx, env->win, 570, 770, 0xFFFFFF, "Julia");
	else if (env->fractal == 2)
		mlx_string_put(env->mlx, env->win, 570, 770, 0xFFFFFF, "Mandelbrot");
	else if (env->fractal == 3)
		mlx_string_put(env->mlx, env->win, 570, 770, 0xFFFFFF, "Burning Ship");
	else
		mlx_string_put(env->mlx, env->win, 570, 770, 0xFFFFFF, "Spiral");
}

void		display_usage(t_fractol *env)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;

	str1 = "To zoom in/zoom out: use +/-  OR scroll mouse";
	str2 = "To increase iterations: press SHIFT OR left mouse button";
	str3 = "To decrease iteractions: press CTRL";
	str4 = "To change color: press C or X OR right mouse button";
	str5 = "To reset changes: press space";
	mlx_string_put(env->mlx, env->win, 10, 5, 0xFFFFFF, "How to use:");
	mlx_string_put(env->mlx, env->win, 10, 25, 0xFFFFFF, "Use arrows to move");
	mlx_string_put(env->mlx, env->win, 10, 45, 0xFFFFFF, str1);
	mlx_string_put(env->mlx, env->win, 10, 65, 0xFFFFFF, str2);
	mlx_string_put(env->mlx, env->win, 10, 85, 0xFFFFFF, str3);
	mlx_string_put(env->mlx, env->win, 10, 105, 0xFFFFFF, str4);
	mlx_string_put(env->mlx, env->win, 10, 125, 0xFFFFFF,
	"To change map: press N");
	mlx_string_put(env->mlx, env->win, 10, 145, 0xFFFFFF, str5);
	mlx_string_put(env->mlx, env->win, 10, 165, 0xFFFFFF, "To exit: press ESC");
	display_name(env);
}

int			ft_checker(char **argv, int argc, t_fractol *env)
{
	if (argc != 2)
	{
		usage();
		return (0);
	}
	if (ft_strcmp(argv[1], "julia") == 0 || ft_strcmp(argv[1], "j")
			== 0)
		env->fractal = 1;
	else if (ft_strcmp(argv[1], "mandelbrot") == 0 || ft_strcmp(argv[1],
				"m") == 0)
		env->fractal = 2;
	else if (ft_strcmp(argv[1], "burningship") == 0 || ft_strcmp(argv[1],
				"b") == 0)
		env->fractal = 3;
	else if (ft_strcmp(argv[1], "spiral") == 0 || ft_strcmp(argv[1],
				"s") == 0)
		env->fractal = 4;
	else
	{
		ft_putendl("wrong name");
		return (0);
	}
	return (1);
}
