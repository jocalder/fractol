/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:32:07 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/03 22:15:39 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(t_fractal *fractal, int keycode)
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
	(void)x;
	(void)y;
	if (keycode == SCROLL_UP)
		fractal->zoom *= 1.1;
	else if (keycode == SCROLL_DOWN)
		fractal->zoom /= 1.1;
	render_fractal(fractal);
	return (0);
}
