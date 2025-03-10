/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:17:22 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/10 20:05:10 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal_types(t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "Mandelbrot", 10) == 0)
	{
		fractal->type = MANDELBROT;
		fractal->min_x = -2.0;
		fractal->max_x = 1.0;
		fractal->min_y = -1.5;
		fractal->max_y = 1.5;
	}
	else if (ft_strncmp(fractal->name, "Burningship", 11) == 0)
	{
		fractal->type = BURNINGSHIP;
		fractal->min_x = -2.0;
		fractal->max_x = 1.0;
		fractal->min_y = -2.0;
		fractal->max_y = 1.0;
	}
}

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
	}
	else if (ft_strncmp(fractal->name, "Mandelbrot", 10) == 0
		|| ft_strncmp(fractal->name, "Burningship", 11) == 0)
		fractal_types(fractal);
	else
	{
		ft_putstr_fd("Usage: ./fractol Invalid type\n", 1);
		ft_putstr_fd("Available: Julia, Mandelbrot and Burningship\n", 1);
		exit_fractal(fractal);
	}
}

void	initialize_fractal(t_fractal *fractal, char **argv, int argc)
{
	init_fractal(fractal);
	init_mlx(fractal);
	parse_args(fractal, argv, argc);
}
