/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:02:05 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/11 17:12:16 by jocalder         ###   ########.fr       */
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
