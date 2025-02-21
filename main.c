/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:43:41 by jocalder          #+#    #+#             */
/*   Updated: 2025/02/21 17:57:16 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handler(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP)
		data->zoom *= 1.1;
	else if (button == SCROLL_DOWN)
		data->zoom /= 1.1;
	return (0);
}

int	key_code(int keycode, t_data *data)
{
	(void)data;
	if (keycode == XK_Escape)
		exit (0);
	return (0);
}

int	main(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->window = mlx_new_window(data->mlx, 1200, 800, "fract'ol");
	data->zoom = 1.0;
	if (!data->window)
		return (1);
	data->zoom = 1.0;
	mlx_mouse_hook(data->window, mouse_handler, data);
	mlx_key_hook(data->window, key_code, data);
	mlx_loop(data->mlx);
	free(data);
	return (0);
}
