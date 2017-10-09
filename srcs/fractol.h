/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:52:00 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/09 06:00:24 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1200
# define HEIGHT 800

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/includes/libft.h"

typedef struct		s_fractol
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	double			zoom;
	int				lock;
	int				c;
	int				bpp;
	int				sline;
	int				endian;
	int				it_max;
	int				s_line;
	int				fractal;
	int				trans_x;
	int				trans_y;
	double			mx;
	double			my;
	double			real;
	double			imag;
}					t_fractol;

typedef struct		s_draw
{
	double			r1;
	double			i1;
	double			r2;
	double			i2;
	double			temp;
}					t_draw;

int					ft_key(int keycode, t_fractol *env);
int					ft_mousemove(int x, int y, t_fractol *env);
int					ft_mouse_key(int key, int x, int y, t_fractol *env);
int					ft_image_put(t_fractol *env);
int					ft_checker(char **argv, int argc, t_fractol *env);
void				draw_pixel(t_fractol *e, int x, int y, int i);
void				ft_print(t_fractol *env);
void				display_usage(t_fractol *env);

#endif
