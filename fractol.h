/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:01:12 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/07 22:56:30 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"

# define SIZE 900
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define JULIA 1
# define MANDELBROT 2
# define BURNINGSHIP 3

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	char	*address;
	void	*image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	//mathematic parameters;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	//user interaction;
	int		type;
	double	zoom;
	int		color;
	char	*name;
	double	julia_cx;
	double	julia_cy;
}	t_fractal;

int		main(int argc, char **argv);
int		parse_args(t_fractal *fractal, char **argv, int argc);
int		exit_fractal(t_fractal *fractal);
int		key_hook(int keycode, t_fractal *fractal);
int		mouse_hook(int key_code, int x, int y, t_fractal *fractal);
int		get_color(t_fractal *fractal, double real, double imaginary);
int		color_selector(t_fractal *fractal, int iteration);
int		compute_iteration(t_fractal *fractal, double real, double imaginary);
//int		math_julia(t_fractal *fractal, double real, double imaginary);
//int		math_mandelbrot(t_fractal *fractal, double real, double imaginary);
//int		math_burningship(t_fractal *fractal, double real, double imaginary);
double	ft_atof(char *str, t_fractal *fractal);
void	parse_julia_args(t_fractal *fractal, char **argv, int argc);
void	parse_other_args(t_fractal *fractal, char **argv, int argc);
void	burningship(double *zr, double *zi);
void	get_pixel(t_fractal *fractal, int x, int y, int color);
void	process_decimal(char *str, double *decimal, double *division);
void	draw_fractal(t_fractal *fractal, char *name);
void	initialize_fractal(t_fractal *fractal, char **argv, int argc);
void	init_mlx(t_fractal *fractal);
void	init_fractal(t_fractal *fractal);
void	render_fractal(t_fractal *fractal);
void	change_color(t_fractal *fractal);
void	move_fractal(t_fractal *fractal, int keycode);

#endif
