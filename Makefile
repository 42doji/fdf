NAME = fdf
CC = cc $(CFLAGS) $(LIBS)
INCLUDES = -Iminilibx-linux -Ilibft -I.
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L. -lmlx_Linux -lm -lX11 -lXext -Iminilibx-linux -lft
SRCS = main.c read_file.c render.c fdf_utils.c render_utils.c render_utils_ii.c matrix_utils.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
MINILIBX = libmlx_Linux.a
LIBFT = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX) $(LIBFT)
	$(CC) $(INCLUDES) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) -c $(SRCS)

$(MINILIBX):
	cd minilibx-linux/ && chmod +x configure && ./configure
	@if [ -f minilibx-linux/libmlx_Linux.a ]; then cp minilibx-linux/libmlx_Linux.a .; fi

$(LIBFT):
	cd libft/ && make
	@if [ -f libft/libft.a ]; then cp libft/libft.a .; fi

clean:
	rm -f $(OBJS)
	cd libft/ && make clean
	cd minilibx-linux/ && make clean

fclean: clean
	rm -f libmlx_Linux.a
	rm -f libft.a
	rm -f $(NAME)
	cd libft/ && make fclean

re: fclean all

.PHONY: all clean fclean re
