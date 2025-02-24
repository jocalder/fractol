/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:17:22 by jocalder          #+#    #+#             */
/*   Updated: 2025/02/23 22:18:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_data *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal, SIZE, SIZE, "fract'ol");
	fractal->image = mlx_new_image(fractal, SIZE, SIZE);
	fractal->adress = mlx_get_data_addr(fractal->image, fractal->bits_per_pixel,
										&fractal->size_line, &fractal->endian);
}
void	init_fractal(t_data *fractal)
{
	fractal->min_x = 
	fractal->max_x = 
	fractal->min_y = 
	fractal->max_y = 
	fractal->offset_x = 
	fractal->offset_y = 
	fractal->ma_iter = 
	fractal->zoom = 
	fractal->color = 
}

void	initialize_fractal(t_data *fractal)
{
	init_mlx(fractal);
	init_fractal(fractal);
}