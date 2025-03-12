/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:17:22 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/12 16:48:07 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal_types(t_fractal *fractal, char **argv)
{
	if (ft_strncmp(fractal->name, "Mandelbrot", 10) == 0)
	{
		fractal->type = MANDELBROT;
		fractal->min_x = ft_atof(argv[2], fractal);
		fractal->max_x = ft_atof(argv[3], fractal);
		fractal->min_y = ft_atof(argv[4], fractal);
		fractal->max_y = ft_atof(argv[5], fractal);
	}
	else if (ft_strncmp(fractal->name, "Burningship", 11) == 0)
	{
		fractal->type = BURNINGSHIP;
		fractal->min_x = ft_atof(argv[2], fractal);
		fractal->max_x = ft_atof(argv[3], fractal);
		fractal->min_y = ft_atof(argv[4], fractal);
		fractal->max_y = ft_atof(argv[5], fractal);
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

void	init_fractal(t_fractal *fractal, char **argv)
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
		fractal->julia_cx = ft_atof(argv[2], fractal);
		fractal->julia_cy = ft_atof(argv[3], fractal);
	}
	else if (ft_strncmp(fractal->name, "Mandelbrot", 10) == 0
		|| ft_strncmp(fractal->name, "Burningship", 11) == 0)
		fractal_types(fractal, argv);
	else
	{
		ft_putstr_fd("Usage: ./fractol Invalid type\n", 1);
		ft_putstr_fd("Available: Julia, Mandelbrot and Burningship\n", 1);
		exit_fractal(fractal);
	}
}

void	initialize_fractal(t_fractal *fractal, char **argv, int argc)
{
	parse_args(fractal, argv, argc);
	init_fractal(fractal, argv);
	init_mlx(fractal);
}
