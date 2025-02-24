/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:36:04 by jocalder          #+#    #+#             */
/*   Updated: 2025/02/24 18:54:24 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    load_image(t_fractal *fractal, char *path)
{
      
}

double	ft_atof(char *str)
{
	double	result;
	int		i;
	int		sign;
	
	result = 0.0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
}

void	parsed_args(t_fractal *fractal, char *argv)
{
	fractal->offset_x = ft_atof(&argv[2]);
	fractal->offset_y = ft_atof(&argv[3]);
}