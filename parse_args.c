/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:44:43 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/07 18:50:44 by jocalder         ###   ########.fr       */
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
	fractal->julia_cx = ft_atof(argv[2], fractal);
	fractal->julia_cy = ft_atof(argv[3], fractal);
}

void	parse_other_args(t_fractal *fractal, char **argv, int argc)
{
	if (argc != 6)
	{
		ft_putstr_fd("Usage: ./fractol Mandelbrot/Burningship\n", 1);
		exit_fractal(fractal);
	}
	fractal->min_x = ft_atof(argv[2], fractal);
	fractal->max_x = ft_atof(argv[3], fractal);
	fractal->min_y = ft_atof(argv[4], fractal);
	fractal->max_y = ft_atof(argv[5], fractal);
}

int	parse_args(t_fractal *fractal, char **argv, int argc)
{
	if (ft_strncmp(fractal->name, "Julia", 5) == 0)
	{
		if (argc != 4)
		{
			ft_putstr_fd("Usage: ./fractol Julia <cx> <cy>\n", 1);
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
