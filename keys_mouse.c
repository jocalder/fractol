/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:32:07 by jocalder          #+#    #+#             */
/*   Updated: 2025/02/28 21:27:50 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(t_fractal *fractal, int keycode)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(fractal->mlx, fractal->window);
		mlx_destroy_image(fractal->mlx, fractal->image);
		mlx_destroy_display(fractal->mlx);
		free(fractal);
		return (0);
	}
	else if (keycode == XK_c)
	{
		change_color(fractal);
	}
	else if (keycode == XK_Left || keycode == XK_Right
		|| keycode == XK_Up || keycode == XK_Down)
	{
		move_fractal(fractal, keycode);
	}
	render_fractal(fractal);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	double	real;
	double	imaginary;

	real = 0.0;
	imaginary = 0.0;
	real = fractal->min_x + (x / (double)SIZE
			* (fractal->max_x - fractal->min_x));
	imaginary = fractal->min_y + (y / (double)SIZE
			* (fractal->max_y - fractal->min_y));
	if (keycode == 4)
		fractal->zoom = 1.1;
	if (keycode == 5)
		fractal->zoom = 0.9;
	if (keycode == 4 || keycode == 5)
	{
		fractal->min_x = real + (fractal->min_x - real) * fractal->zoom;
		fractal->max_x = real + (fractal->max_x - real) * fractal->zoom;
		fractal->min_y = imaginary + (fractal->min_y - imaginary)
			* fractal->zoom;
		fractal->max_y = imaginary + (fractal->max_y - imaginary)
			* fractal->zoom;
		render_fractal(fractal);
	}
	return (0);
}




