/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:32:07 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/07 20:28:54 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == XK_Escape)
		exit_fractal(fractal);
	else if (keycode == XK_c)
		change_color(fractal);
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
	double	zoom_move;

	real = fractal->min_x + (x / (double)SIZE)
		* (fractal->max_x - fractal->min_x);
	imaginary = fractal->min_y + (y / (double)SIZE)
		* (fractal->max_y - fractal->min_y);
	if (keycode == SCROLL_UP)
		zoom_move = 1.1;
	else if (keycode == SCROLL_DOWN)
		zoom_move = 0.9;
	else
		return (0);
	fractal->min_x = real + (fractal->min_x - real) * zoom_move;
	fractal->max_x = real + (fractal->max_x - real) * zoom_move;
	fractal->min_y = imaginary + (fractal->min_y - imaginary) * zoom_move;
	fractal->max_y = imaginary + (fractal->max_y - imaginary) * zoom_move;
	render_fractal(fractal);
	return (0);
}
