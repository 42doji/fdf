/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:20:20 by doji              #+#    #+#             */
/*   Updated: 2024/05/18 19:37:23 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cleanup(t_fdf *data)
{
	if (data)
	{
		if (data->mlx_ptr)
		{
			if (data->win_ptr)
				mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			if (data->img_ptr)
				mlx_destroy_image(data->mlx_ptr, data->img_ptr);
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
		}
		free_matrix(data->matrix);
		free(data);
	}
}

int	check_file_access(const char *file_path)
{
	if (access(file_path, F_OK) == 0)
	{
		if (access(file_path, R_OK) != 0)
			return (0);
		if (access(file_path, W_OK) != 0)
			return (0);
		else
			return (1);
	}
	else
		return (0);
}

int	key_handler(int key, t_fdf *data)
{
	if (data == NULL)
		return (-1);
	if (key == 65362)
		data->shift_y -= 10;
	if (key == 65364)
		data->shift_y += 10;
	if (key == 65363)
		data->shift_x += 10;
	if (key == 65361)
		data->shift_x -= 10;
	if (key == 65307)
	{
		cleanup(data);
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	render(data);
	return (0);
}

void	init_data(t_fdf *d)
{
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		exit(1);
	d->win_ptr = mlx_new_window(d->mlx_ptr, 1000, 1000, "FDF");
	if (!d->win_ptr)
		exit(1);
	d->img_ptr = mlx_new_image(d->mlx_ptr, 1000, 1000);
	if (!d->img_ptr)
		exit(1);
	d->img_data = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->sl, &d->edn);
	if (!d->img_data)
		exit(1);
	d->z_scale = 10;
	d->shift_x = 500;
	d->shift_y = 300;
	d->color = 0xFFFFFF;
}

int	main(int argc, char *argv[])
{
	t_fdf	*data;

	if (argc != 2 || !check_file_access(argv[1]))
		return (1);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (1);
	read_file(argv[1], data);
	init_data(data);
	render(data);
	mlx_key_hook(data->win_ptr, (int (*)())key_handler, data);
	mlx_loop(data->mlx_ptr);
	cleanup(data);
	return (0);
}
