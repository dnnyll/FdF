# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 13:24:44 by daniefe2          #+#    #+#              #
#    Updated: 2025/03/01 11:25:35 by daniefe2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Paths
MLX_DIR = lib/minilibx-linux
PRINTF_DIR = lib/ft_printf
LIBFT_DIR = lib/Libft

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -I./headers

# Libraries
MLX = -L $(MLX_DIR) -lmlx -lX11 -lXext -lm -lz -lGL
PRF = -L $(PRINTF_DIR) -lftprintf
LIB = -L $(LIBFT_DIR) -lft

# Source files
SRCS =	sources/main.c \
		sources/maps/initialize_map.c \
		lib/get_next_line/get_next_line.c \
		lib/get_next_line/get_next_line_utils.c \
		sources/maps/atoi_base.c \
		sources/maps/convert_to_int.c \
		sources/memory/free_grids.c \
		sources/memory/free_matrix.c \
		sources/memory/free_ressources.c \
		sources/memory/alloc_char_matrix.c \
		sources/memory/alloc_int_matrix.c \
		sources/maps/initialize_matrices.c \
		sources/maps/map_parsing.c \
		sources/maps/read_map.c \
		sources/maps/coordinates_grid.c \
		sources/maps/iso_conversion.c \
		sources/maps/coodinates_shifting.c \
		sources/maps/rendering_projection.c \
		sources/maps/bersenham.c \
		sources/maps/set_pixel.c \
		sources/maps/operations.c \
		sources/maps/input_check.c \
		sources/window_hooks/window_hooks.c

OBJS = $(SRCS:.c=.o)
NAME = fdf

# Ensure libraries are built before linking
all: libft printf mlx $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) $(PRF) $(LIB)

# Ensure libraries are compiled
libft:
	make -C $(LIBFT_DIR) all

printf:
	make -C $(PRINTF_DIR) all

mlx:
	make -C $(MLX_DIR) all

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all

test: all
	./fdf
