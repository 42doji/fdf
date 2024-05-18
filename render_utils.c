/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:41:17 by doji              #+#    #+#             */
/*   Updated: 2024/05/18 19:41:18 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	maax(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	mod(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void	init_steps(float *x_step, float *y_step, float x, float y)
{
	float	max;

	*x_step = x;
	*y_step = y;
	max = maax(mod(*x_step), mod(*y_step));
	*x_step /= max;
	*y_step /= max;
}

void	set_color(int z, int z1, t_fdf *data)
{
	if (z || z1)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}
