/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:33:37 by jocalder          #+#    #+#             */
/*   Updated: 2025/02/27 18:34:48 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_fractal(t_fractal *fractal, int keycode)
{
	double	move;

	move = (fractal->max_x - fractal->min_x) * 0.1;
	if (keycode == XK_Left)
		fractal->offset_x -= move;
	if (keycode == XK_Right)
		fractal->offset_x += move;
	if (keycode == XK_Up)
		fractal->offset_y -= move;
	if (keycode == XK_Down)
		fractal->offset_y += move;
}

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