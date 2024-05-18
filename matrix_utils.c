/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:41:00 by doji              #+#    #+#             */
/*   Updated: 2024/05/18 19:41:01 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_matrix(int *m_line, char *line, int width)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i] && i < width)
	{
		m_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	clean_matrix(int **matrix, int i)
{
	while (--i >= 0)
		free(matrix[i]);
	free(matrix);
}

void	free_matrix(int **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	matrix_len(int *matrix)
{
	int	i;

	if (!matrix)
		return (0);
	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	is_valid_matrix(t_fdf *data, int width)
{
	int	i;

	if (!data || !data->matrix)
		return (0);
	i = 0;
	while (data->matrix[i])
	{
		if (matrix_len(data->matrix[i]) != width)
		{
			free_matrix(data->matrix);
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			free(data);
			return (0);
		}
		i++;
	}
	return (1);
}
