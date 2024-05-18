/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_ii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:41:26 by doji              #+#    #+#             */
/*   Updated: 2024/05/18 19:41:27 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_scale_x(float *x, float *x1, t_fdf *data)
{
	*x *= data->z_scale;
	*x1 *= data->z_scale;
	*x += data->shift_x;
	*x1 += data->shift_x;
}

void	set_scale_y(float *y, float *y1, t_fdf *data)
{
	*y *= data->z_scale;
	*y1 *= data->z_scale;
	*y += data->shift_y;
	*y1 += data->shift_y;
}

void	init_x1(float *x1, float x, int flag)
{
	if (flag)
		*x1 = x + 1;
	else
		*x1 = x;
}

void	init_y1(float *y1, float y, int flag)
{
	if (flag)
		*y1 = y;
	else
		*y1 = y + 1;
}
