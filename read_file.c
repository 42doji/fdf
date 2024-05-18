/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:40:30 by doji              #+#    #+#             */
/*   Updated: 2024/05/18 19:40:31 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *filename)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(filename, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	while (line && *line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (height);
}

int	get_width(char *filename)
{
	char	*line;
	int		width;
	int		fd;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	width = count_words(line, " ");
	free(line);
	close(fd);
	return (width);
}

void	init_readfiles(char *filename, t_fdf *data)
{
	data->height = get_height(filename);
	data->width = get_width(filename);
	data->matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
}

void	loop_matrix(int fd, t_fdf *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line && *line)
	{
		make_matrix(data->matrix[i], line, data->width);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
}

void	read_file(char *filename, t_fdf *data)
{
	int		fd;
	int		i;

	init_readfiles(filename, data);
	if (!data->matrix)
		return ;
	i = 0;
	while (i < data->height)
	{
		data->matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (!data->matrix[i])
		{
			clean_matrix(data->matrix, i);
			return ;
		}
		i++;
	}
	fd = open(filename, O_RDONLY);
	loop_matrix(fd, data);
	data->matrix[i] = (void *)0;
	close(fd);
}
