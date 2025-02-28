/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:33:37 by jocalder          #+#    #+#             */
/*   Updated: 2025/02/28 21:20:53 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_fractal *fractal)
{
	int		x;
	int		y;
	double	real;
	double	imaginary;
	int		color;

	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			real = fractal->min_x + (x / (double)SIZE)
				* (fractal->max_x - fractal->min_x) + fractal->offset_x;
			imaginary = fractal->min_y + (x / (double)SIZE)
				* (fractal->max_y - fractal->min_y) + fractal->offset_y;
			color = get_color(fractal, real, imaginary);
			get_pixel(fractal, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx,
		fractal->window, fractal->image, 0, 0);
}

void	move_fractal(t_fractal *fractal, int keycode)
{
	double	move_x;
	double	move_y;

	move_x = (fractal->max_x - fractal->min_x) * 0.1;
	move_y = (fractal->max_y - fractal->min_y) * 0.1;
	if (keycode == XK_Left)
	{
		fractal->max_x -= move_x;
		fractal->min_x -= move_x;
	}
	if (keycode == XK_Right)
	{
		fractal->max_x += move_x;
		fractal->min_x += move_x;
	}
	if (keycode == XK_Up)
	{
		fractal->max_y -= move_y;
		fractal->min_y -= move_y;
	}
	if (keycode == XK_Down)
	{
		fractal->max_y += move_y;
		fractal->min_y += move_y;
	}
}

int	get_color(t_fractal *fractal, double real, double imaginary)
{
	int	iteration;

	iteration = compute_iteration(fractal, real, imaginary);
	if (iteration = fractal->max_iter)
		return (0x000000);
	return (fractal->color * iteration / fractal->max_iter);
}

void	get_pixel(t_fractal *fractal, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x <= SIZE || y < 0 || y <= SIZE)
		return ;
	pixel = fractal->address + (y * fractal->size_line + x * (fractal->bits_per_pixel / 8));
	*(int *)pixel = color;
}

void	init_complex(t_fractal *fractal, double *zr, double *zi, double real, double imaginary)
{
	if (fractal->type == MANDELBROT)
	{
		*zr = 0;
		*zi = 0;
	}
	else
	{
		*zr = real;
		*zi = imaginary;
	}
}

void	apply_formula(t_fractal *fractal, double *zr, double *zi, double real, double imaginary)
{
	double	temp;

	if (fractal->type == BURNINGSHIP)
	{
		*zr = fabs(*zr);
		*zi = fabs(*zi);
	}
	temp = (*zr * *zr) - (*zi * *zi);
	*zi = 2 * (*zr) * (*zi);
	if (fractal->type == MANDELBROT || fractal->type == BURNINGSHIP)
	{
		temp += real;
		*zi += imaginary;
	}
	else
	{
		temp += fractal->julia_cx;
		*zi += fractal->julia_cy;
	}
	*zr = temp;
}

int	compute_iterations(t_fractal *fractal, double real, double imaginary)
{
	int		iter;
	double	zr;
	double	zi;

	init_complex(fractal, &zr, &zi, real, imaginary);
	iter = 0;
	while (iter < fractal->max_iter && (zr * zr + zi * zi) <= 4.0)
	{
		apply_formula(fractal, &zr, &zi, real, imaginary);
		iter++;
	}
	return (iter);
}


