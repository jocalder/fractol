/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:05:44 by marvin            #+#    #+#             */
/*   Updated: 2025/02/23 23:05:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fractal(t_fractal *fractal)
{
	if (!fractal)
		return (0);
	if (fractal->image && fractal->mlx)
		mlx_destroy_image(fractal->mlx, fractal->image);
	if (fractal->window && fractal->mlx)
	{
		mlx_clear_window(fractal->mlx, fractal->window);
		mlx_destroy_window(fractal->mlx, fractal->window);
	}
	if (fractal->mlx)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	free(fractal);
	exit(0);
	return (0);
}
