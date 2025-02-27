/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:36:04 by jocalder          #+#    #+#             */
/*   Updated: 2025/02/27 18:31:12 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_args(t_fractal *fractal, char **argv, int argc)
{
	int	is_mandelbrot_or_burning;

	is_mandelbrot_or_burning = ft_strncmp(argv[1], "Mandelbrot", 10) == 0
		|| ft_strncmp(argv[1], "Burningship", 11) == 0;
	fractal->name = argv[1];
	if (ft_strncmp(argv[1], "Julia", 5) == 0 && argc == 4)
	{
		fractal->julia_cx = ft_atof(argv[2]);
		fractal->julia_cy = ft_atof(argv[3]);
	}
	else if (is_mandelbrot_or_burning && argc == 6)
	{
		fractal->min_x = ft_atof(argv[2]);
		fractal->max_x = ft_atof(argv[3]);
		fractal->min_y = ft_atof(argv[4]);
		fractal->max_y = ft_atof(argv[5]);
	}
	else
	{
		ft_putstr_fd("Usage: ./fractol Invalid type\n", 1);
		ft_putstr_fd("Available: Julia, Mandelbrot and Burningship\n", 1);
		exit_fractal(fractal);
	}
	return (0);
}

void	process_decimal(char *str, double *decimal, double *division)
{
	while (*str >= '0' && *str <= '9')
	{
		*decimal = *decimal * 10.0 + (*str - '0');
		*division *= 10.0;
		str++;
	}
}

double	ft_atof(char *str)
{
	double	division;
	double	result;
	double	decimal;
	int		sign;

	division = 1.0;
	result = 0.0;
	decimal = 0.0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str++ - '0');
	}
	if (*str == '.')
		process_decimal(++str, &decimal, &division);
	return (sign * (result + (decimal / division)));
}

void	change_color(t_fractal *fractal)
{
	static int	color_change;

	color_change = (color_change + 1) % 3;
	if (color_change == 0)
		fractal->color = 0xFF0000;
	else if (color_change == 1)
		fractal->color = 0x00FF00;
	else
		fractal->color = 0x0000FF;
}
