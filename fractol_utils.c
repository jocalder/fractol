/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:36:04 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/07 22:54:46 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdbool.h>

static bool	is_valid_char(char c)
{
	return (c == '.' || c == '-' || c == '+' || (c >= '0' && c <= '9'));
}

static bool	validate_string(char *str)
{
	bool has_sign = false;
	bool has_dot = false;

	if (*str == '-' || *str == '+')
	{
		has_sign = true;
		str++;
	}
	while (*str)
	{
		if (!is_valid_char(*str))
			return (false);
		if (*str == '.')
		{
			if (has_dot)
				return (false);
			has_dot = true;
			//if (*str++ == '-' || *str++ == '+')
			//	return (false);
		}
		if ((*str == '-' || *str == '+') && has_sign)
			return (false);
		str++;
	}
	return (true);
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

double	ft_atof(char *str, t_fractal *fractal)
{
	double	division;
	double	result;
	double	decimal;
	int		sign;

	division = 1.0;
	result = 0.0;
	decimal = 0.0;
	sign = 1;
	if (!validate_string(str))
	{
		ft_putstr_fd("Use valid values\n", 1);
		exit_fractal(fractal);
	}
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
		process_decimal(++str, &decimal, &division);
	return (sign * (result + (decimal / division)));
}

void	burningship(double *zr, double *zi)
{
	*zr = fabs(*zr);
	*zi = fabs(*zi);
}

int	compute_iteration(t_fractal *fractal, double real, double imaginary)
{
	int		iter;
	double	zr;
	double	zi;
	double	tmp;

	iter = 0;
	zr = 0.0;
	zi = 0.0;
	if (fractal->type == JULIA)
	{
		zr = real;
		zi = imaginary;
		real = fractal->julia_cx;
		imaginary = fractal->julia_cy;
	}
	while (zr * zr + zi * zi <= 4.0 && iter < fractal->max_iter)
	{
		if (fractal->type == BURNINGSHIP)
			burningship(&zr, &zi);
		tmp = zr * zr - zi * zi + real;
		zi = 2.0 * zr * zi + imaginary;
		zr = tmp;
		iter++;
	}
	return (iter);
}