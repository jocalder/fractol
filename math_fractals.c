/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:02:05 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/09 23:16:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	burningship(double *zr, double *zi)
{
	*zr = fabs(*zr);
	*zi = fabs(*zi);
}

int	compute_iteration(t_fractal *fractal, double real, double imaginary)
{
	int		iter;
	double	zr;
	double	zi;
	double	tmp;

	iter = 0;
	zr = 0.0;
	zi = 0.0;
	if (fractal->type == JULIA)
	{
		zr = real;
		zi = imaginary;
		real = fractal->julia_cx;
		imaginary = fractal->julia_cy;
	}
	while (zr * zr + zi * zi <= 4.0 && iter < fractal->max_iter)
	{
		if (fractal->type == BURNINGSHIP)
			burningship(&zr, &zi);
		tmp = zr * zr - zi * zi + real;
		zi = 2.0 * zr * zi + imaginary;
		zr = tmp;
		iter++;
	}
	return (iter);
}

int	math_julia(t_fractal *fractal, double real, double imaginary)
{
	int		iter;
	double	zx;
	double	zy;
	double	temp;

	zx = real;
	zy = imaginary;
	temp = 0.0;
	iter = 0;
	while (zx * zx + zy * zy <= 4.0 && iter < fractal->max_iter)
	{
		temp = zx * zx - zy * zy + fractal->julia_cx;
		zy = 2.0 * zx * zy + fractal->julia_cx;
		zx = temp;
		iter++;
	}
	return (iter);
}

int	math_mandelbrot(t_fractal *fractal, double real, double imaginary)
{
	int		iter;
	double	zx;
	double	zy;
	double	temp;

	zx = 0.0;
	zy = 0.0;
	temp = 0.0;
	iter = 0;
	while (zx * zx + zy * zy <= 4.0 && iter < fractal->max_iter)
	{
		temp = zx * zx - zy * zy + real;
		zx = 2.0 * zx * zy + imaginary;
		zx = temp;
		iter++;
	}
	return (iter);
}

int	math_burningship(t_fractal *fractal, double real, double imaginary)
{
	int		iter;
	double	zx;
	double	zy;
	double	temp;

	zx = 0.0;
	zy = 0.0;
	temp = 0.0;
	iter = 0;
	while (zx * zx + zy * zy <= 4.0 && iter < fractal->max_iter)
	{
		zx = fabs(zx);
		zy = fabs(zy);
		temp = zx * zx - zy * zy + real;
		zy = 2.0 * zx * zy + imaginary;
		zx = temp;
		iter++;
	}
	return (iter);
}
