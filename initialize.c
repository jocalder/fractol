/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:17:22 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/04 17:29:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "fract'ol");
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->address = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	fractal->max_iter = 70;
	fractal->zoom = 1.0;
	fractal->color = 0xFFFFFF;
	if (ft_strncmp(fractal->name, "Julia", 6) == 0)
	{
		fractal->type = JULIA;
		fractal->min_x = -2.0;
		fractal->max_x = 2.0;
		fractal->min_y = -2.0;
		fractal->max_y = 2.0;
		fractal->julia_cx = 0.285;
		fractal->julia_cy = 0.01;
		printf("init Julia\n");
	}
	else if (ft_strncmp(fractal->name, "Mandelbrot", 10) == 0)
	{
		fractal->type = MANDELBROT;
		fractal->min_x = -2.0;
		fractal->max_x = 1.0;
		fractal->min_y = -1.5;
		fractal->max_y = 1.5;
		printf("init Mandelbrot\n");
	}
	else if (ft_strncmp(fractal->name, "Burningship", 11) == 0)
	{
		fractal->type = BURNINGSHIP;
		fractal->min_x = -2.0;
		fractal->max_x = 1.0;
		fractal->min_y = -2.0;
		fractal->max_y = 1.0;
		printf("init Burningship\n");
	}
}

void	initialize_fractal(t_fractal *fractal, char **argv, int argc)
{
	init_fractal(fractal);
	parse_args(fractal, argv, argc);
	init_mlx(fractal);
}
