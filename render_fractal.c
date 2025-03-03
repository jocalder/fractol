/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:33:37 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/03 19:52:29 by jocalder         ###   ########.fr       */
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
		return (0x000000);
	return (color_selector(fractal));
}

void	change_color(t_fractal *fractal)
{
	fractal->color = (fractal->color + 1) % 2;
}