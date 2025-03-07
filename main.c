/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:43:41 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/07 20:30:05 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_window(t_fractal *fractal)
{
	exit_fractal(fractal);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2)
	{
		ft_putstr_fd("Usage: ./fractol Invalid type\n", 1);
		ft_putstr_fd("Available: Julia, Mandelbrot and Burningship\n", 1);
		return (1);
	}
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
	{
		ft_putstr_fd("Error: Memory allocation failed\n", 1);
		return (1);
	}
	fractal->name = argv[1];
	initialize_fractal(fractal, argv, argc);
	mlx_hook(fractal->window, 17, 0, close_window, fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_loop(fractal->mlx);
	exit_fractal(fractal);
	return (0);
}
