/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:33:37 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/09 23:13:48 by marvin           ###   ########.fr       */
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
			imaginary = fractal->min_y + (y / (double)SIZE)
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

void	get_pixel(t_fractal *fractal, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
		return ;
	pixel = fractal->address + (y * fractal->size_line + x
			* (fractal->bits_per_pixel / 8));
	*(int *)pixel = color;
}

int	get_color(t_fractal *fractal, double real, double imaginary)
{
	int	iteration;

	iteration = compute_iteration(fractal, real, imaginary);
	if (iteration == fractal->max_iter)
		return (0xFF0000);
	return (color_selector(fractal, iteration));
}

void	change_color(t_fractal *fractal)
{
	fractal->color = (fractal->color + 1) % 4;
}