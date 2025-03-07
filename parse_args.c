/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:44:43 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/04 17:57:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_julia_args(t_fractal *fractal, char **argv, int argc)
{
	if (argc != 4)
	{
		ft_putstr_fd("Usage: ./fractol Julia <cx> <cy>\n", 1);
		exit_fractal(fractal);
	}
	fractal->julia_cx = ft_atof(argv[1]);
	printf("julia_cx: %f\n", fractal->julia_cx);
	fractal->julia_cy = ft_atof(argv[2]);
	printf("julia_cy: %f\n", fractal->julia_cy);
	if (fractal->julia_cx == 0.0 && fractal->julia_cy == 0.0)
	{	
		ft_putstr_fd("Use valid values: <cx> <cy>\n", 1);
		exit_fractal(fractal);
	}
}

void	parse_other_args(t_fractal *fractal, char **argv, int argc)
{
	if (argc != 6)
	{
		ft_putstr_fd("Usage: ./fractol Mandelbrot/Burningship\n", 1);
		exit_fractal(fractal);
	}
	fractal->min_x = ft_atof(argv[1]);
	printf("min_x: %f\n", fractal->min_x);
	fractal->max_x = ft_atof(argv[2]);
	printf("max_x: %f\n", fractal->max_x);
	fractal->min_y = ft_atof(argv[3]);
	printf("min_y: %f\n", fractal->min_y);
	fractal->max_y = ft_atof(argv[4]);
	printf("max_y: %f\n", fractal->max_y);
}

int	parse_args(t_fractal *fractal, char **argv, int argc)
{
	if (ft_strncmp(fractal->name, "Julia", 5) == 0)
	{
		if (argc != 4)
		{
			ft_putstr_fd("Usage: ./fractol Juia <cx> <cy>\n", 1);
			exit_fractal(fractal);
		}
		parse_julia_args(fractal, argv, argc);
	}
	else if (ft_strncmp(fractal->name, "Mandelbrot", 10) == 0
		|| ft_strncmp(fractal->name, "Burningship", 11) == 0)
		parse_other_args(fractal, argv, argc);
	else
	{
		ft_putstr_fd("Available: Julia, Mandelbrot, Burningship\n", 1);
		exit_fractal(fractal);
	}
	return (0);
}
