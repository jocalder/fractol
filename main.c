/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:43:41 by jocalder          #+#    #+#             */
/*   Updated: 2025/02/21 19:18:43 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_fractal *fractal, char *name)
{
	
}

int	main(void)
{
	t_data	*fractal;

	if (argc != 2)
	{
		ft_putstr_fd("Available fractals: Mandelbrot and Julia");
		return (0);
	}
	fractal = malloc(sizeof(t_data));
	initialize_fractal(fractal);
	return (0);
}
