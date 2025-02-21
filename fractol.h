/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:01:12 by jocalder          #+#    #+#             */
/*   Updated: 2025/02/21 18:40:06 by jocalder         ###   ########.fr       */
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

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_data
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
	int		fractal;
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
}	t_data;

int	main(void);
int	key_code(int keycode, t_data *data);
int	mouse_handler(int button, int x, int y, t_data *data);

#endif