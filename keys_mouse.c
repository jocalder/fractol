/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:32:07 by jocalder          #+#    #+#             */
/*   Updated: 2025/02/24 17:51:07 by jocalder         ###   ########.fr       */
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
		fractal->color = 
	}
	else if (keycode == XK_Left)
	else if (keycode == XK_Right)
	else if (keycode == XK_Up)
	else if (keycode == XK_Down)
}

void	zoom(t_fractal *fractal, int x, int y, int zoom_direction)
{
	
}
int	mouse_hook(int keycode, t_fractal *fractal)
{
	if ()
}
