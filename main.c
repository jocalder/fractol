/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:43:41 by jocalder          #+#    #+#             */
/*   Updated: 2025/02/27 17:33:11 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*void	draw_fractal(t_fractal *fractal, char *name)
{
	if (ft_strncmp(name, "Julia", 5) == 0)
		draw_julia(fractal);
	else if (ft_strncmp(name, "Mandelbrot", 10) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(name, "Burningship", 11) == 0)
		draw_burningship(fractal);
	else
	{
		ft_putstr_fd("Usage: ./fractol Invalid type", 1);
		ft_putstr_fd("Available fractals: Mandlebrot and Julia\n", 1);
		free(fractal);
	}
}*/

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2)
	{
		ft_putstr_fd("Usage: ./fractol Invalid type\n", 1);
		ft_putstr_fd("Available: Julia, Mandelbrot and Burningship\n", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (1);
	parse_args(fractal, &argv[1], (argc -1));
	initialize_fractal(fractal, &argv[1]);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_loop(fractal->mlx);
	return (0);
}
