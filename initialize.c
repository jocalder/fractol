/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:17:22 by jocalder          #+#    #+#             */
/*   Updated: 2025/02/24 18:53:23 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal, SIZE, SIZE, "fract'ol");
	fractal->image = mlx_new_image(fractal, SIZE, SIZE);
	fractal->adress = mlx_get_data_addr(fractal->image, &fractal->bits_per_pixel,
										&fractal->size_line, &fractal->endian);
}
void	init_fractal(t_fractal *fractal)
{
	fractal->min_x = -2.0;
	fractal->max_x = 2.0;
	fractal->min_y = -2.0;
	fractal->max_y = 2.0;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	fractal->max_iter = 70;
	fractal->zoom = 1.0;
	fractal->color = 0;
}

void	initialize_fractal(t_fractal *fractal)
{
	init_mlx(fractal);
	init_fractal(fractal);
}