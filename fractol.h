/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:01:12 by jocalder          #+#    #+#             */
/*   Updated: 2025/02/23 23:01:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"

# define SIZE 600
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	char	*adress;
	void	*image;
	void	*ptr_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	//mathematic parameters;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	//user interaction;
	double	zoom;
	int		color;
	char	*name;
}	t_fractal;

int		main(int argc, char **argv);
void	draw_fractal(t_fractal *fractal, char *name);
void	initialize_fractal(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);
void	init_fractal(t_fractal *fractal);
void	draw_julia(t_fractal *fractal);
void	draw_mandlebrot(t_fractal *fractal);
void	calculate_julia(t_fractal *fractal);
void	calculate_mandlebrot(t_fractal *fractal);

#endif