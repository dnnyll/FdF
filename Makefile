# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 13:24:44 by daniefe2          #+#    #+#              #
#    Updated: 2025/02/10 08:56:50 by daniefe2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I./headers

# Source files and object files
SRCS =	sources/main.c \
		sources/maps/initialize_map.c \
		lib/get_next_line/get_next_line.c \
		lib/get_next_line/get_next_line_utils.c \
		sources/printers/matrix_printer.c \
 		sources/converters/atoi_base.c \
		sources/converters/convert_to_int.c \
		sources/memory/matrix_mem_alloc.c \
		sources/memory/free_matrix.c \
		sources/memory/free_coordinates_grid.c \
		sources/maps/map_parsing.c \
		sources/maps/read_map.c \
		sources/maps/coordinates_grid.c \
		sources/maps/iso_conversion.c \
		sources/maps/coodinates_shifting.c \
		sources/maps/rendering_projection.c \
		sources/keys/maping_keys.c \
		sources/colour_management/rgb.c \
		sources/window_management/window.c

# Automatically generate object files from .c files
OBJS = $(SRCS:%.c=%.o)

# Name of the output executable
NAME = fdf

# MLX, ft_printf, and Libft libraries
MLX = -L lib/minilibx-linux -lmlx -lX11 -lXext -lm -lz -lGL
PRF = -L lib/ft_printf -lftprintf
LIB = -L lib/Libft -lft


# Default target to build the program
all: $(NAME)

# Rule to create the final executable
# Calls libraries MLX, PRF, LIB
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(PRF) $(LIB) -o $(NAME)  # Link the object files to create the final executable

# Pattern rule to compile .c files from sources/ into .o object files
%.o: sources/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Target to remove all object files
clean:
	rm -f $(OBJS)  # Remove the object files

# Target to remove both the object files and the final executable
fclean: clean
	rm -f $(NAME)  # Remove the final executable

test: all
	./fdf

# Target to clean and then rebuild everything from scratch
re: fclean all
