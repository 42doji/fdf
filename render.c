/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:40:48 by doji              #+#    #+#             */
/*   Updated: 2024/05/18 19:40:49 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(1) - z;
}

void	put_pixel_to_image(t_fdf *data, int x, int y)
{
	int	index;

	if (x >= 0 && x < 1000 && y >= 0 && y < 1000)
	{
		index = (x * 4) + (y * data->sl);
		data->img_data[index] = data->color & 0xFF;
		data->img_data[index + 1] = (data->color >> 8) & 0xFF;
		data->img_data[index + 2] = (data->color >> 16) & 0xFF;
		data->img_data[index + 3] = (data->color >> 24) & 0xFF;
	}
}

void	bresenham(float x, float y, int flag, t_fdf *d)
{
	float	steps[2];
	float	pr[2];
	int		z;
	int		z1;

	init_x1(&pr[0], x, flag);
	init_y1(&pr[1], y, flag);
	z = d->matrix[(int)y][(int)x];
	z1 = d->matrix[(int)pr[1]][(int)pr[0]];
	z *= d->z_scale * 0.09;
	z1 *= d->z_scale * 0.09;
	set_color(z, z1, d);
	isometric(&x, &y, z);
	isometric(&pr[0], &pr[1], z1);
	set_scale_x(&x, &pr[0], d);
	set_scale_y(&y, &pr[1], d);
	init_steps(&steps[0], &steps[1], pr[0] - x, pr[1] - y);
	while ((int)(x - pr[0]) != 0 || (int)(y - pr[1]) != 0)
	{
		put_pixel_to_image(d, (int)x, (int)y);
		x += steps[0];
		y += steps[1];
	}
	put_pixel_to_image(d, (int)pr[0], (int)pr[1]);
}

void	render(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, 1, data);
			if (y < data->height - 1)
				bresenham(x, y, 0, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
