/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:19:43 by doji              #+#    #+#             */
/*   Updated: 2024/05/18 21:20:18 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include "minilibx-linux/mlx.h"

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		**matrix;
	int		bpp;
	int		sl;
	int		edn;
	int		width;
	int		height;
	int		z_scale;
	int		color;
	int		shift_x;
	int		shift_y;
}	t_fdf;

int     	close_window(t_fdf *data);
int		is_in_word(int *count, int in_word);
int		is_split(char c, const char *delimiter);
int		count_words(const char *word, char *delimiter);
int		check_file_access(const char *file_path);
int		get_height(char *filename);
int		get_width(char *filename);
int		key_handler(int key, t_fdf *data);
int		matrix_len(int *matrix);
void	init_x1(float *x1, float x, int flag);
void	init_y1(float *y1, float y, int flag);
void	free_matrix(int **matrix);
void	make_matrix(int *m_line, char *line, int width);
void	clean_matrix(int **matrix, int i);
void	loop_matrix(int fd, t_fdf *data);
void	init_readfiles(char *filename, t_fdf *data);
void	init_data(t_fdf *data);
void	set_scale_x(float *x, float *x1, t_fdf *data);
void	set_scale_y(float *y, float *y1, t_fdf *data);
void	init_steps(float *x_step, float *y_step, float x, float y);
void	set_color(int z, int z1, t_fdf *data);
void	read_file(char *filename, t_fdf *data);
void	isometric(float *x, float *y, int z);
void	bresenham(float x, float y, int flag, t_fdf *data);
void	render(t_fdf *data);
void	cleanup(t_fdf *data);
void	put_pixel_to_image(t_fdf *data, int x, int y);
float	mod(float a);
float	maax(float a, float b);
#endif
