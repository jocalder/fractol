/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:43:41 by jocalder          #+#    #+#             */
/*   Updated: 2025/02/24 13:42:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractal *fractal, char *name)
{
	if (ft_strncmp(name, "julia", 5) == 0)
		draw_julia(fractal);
	else if (ft_strncmp(name, "mandlebrot", 10) == 0)
		draw_mandlebrot(fractal);
	else
	{
		ft_putstr_fd("Usage: ./fractol <fractal>", 1);
		ft_putstr_fd("Available fractals: Mandlebrot and Julia\n", 1);
		free(fractal);
	}
}

int	main(int argc, char **argv)
{
	t_data	*fractal;

	if (argc != 2)
	{
		ft_putstr("Usage: ./fractol <fractal>\n", 1)
		ft_putstr_fd("Available fractals: Mandelbrot and Julia\n", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (free(fractal), 1);
	initialize_fractal(fractal);
	if (argv[1] == "Julia")
		load_image(fractal, ".....xpm");
	else
		load_image(fractal, ".....xpm");
	draw_fractal(fractal, argv[1]);
	return (0);
}
