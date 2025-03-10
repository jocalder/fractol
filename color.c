/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:05:32 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/10 18:43:17 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static int	color_origin(t_fractal *fractal, int iteration)
{
	int		red;
	int		blue;
	int		green;
	double	t;

	t = (double)iteration / (double)fractal->max_iter;
	red = (int)(sin((t * M_PI * 2) * 0.5 + 0.5) * 255);
	blue = (int)(sin(((t + 0.33) * M_PI * 2) * 0.5 + 0.5) * 255);
	green = (int)(sin(((t + 0.66) * M_PI * 2) * 0.5 + 0.5) * 255);
	return ((red << 16 | green << 8 | blue));
}

static int	color_variation(t_fractal *fractal, int iteration)
{
	int		red;
	int		blue;
	int		green;
	double	t;

	t = (double)iteration / (double)fractal->max_iter;
	red = (int)(sin((t * M_PI * 3) * 0.5 + 0.5) * 255);
	blue = (int)(sin(((t + 0.5) * M_PI * 2) * 0.5 + 0.5) * 255);
	green = (int)(sin(((t + 1.0) * M_PI * 2) * 0.5 + 0.5) * 255);
	return ((red << 16 | green << 8 | blue));
}

int	color_selector(t_fractal *fractal, int iteration)
{
	if (fractal->color == 0)
		return (color_origin(fractal, iteration));
	return (color_variation(fractal, iteration));
}
