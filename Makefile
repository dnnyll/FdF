# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 13:24:44 by daniefe2          #+#    #+#              #
#    Updated: 2025/01/08 11:01:20 by daniefe2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./headers

# Source files and object files
SRCS = sources/main.c \
       sources/render.c \
       sources/initialize_mlx.c \
       sources/handle_key.c \
	   sources/handle_close.c \
       sources/cleanup_window.c

# Automatically generate object files from .c files
OBJS = $(SRCS:%.c=%.o)

# Name of the output executable
NAME = fdf

# MLX library path and libraries
MLX = -L lib/minilibx-linux -lmlx -lX11 -lXext -lm -lz -lGL

# Default target to build the program
all: $(NAME)

# Rule to create the final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)  # Link the object files to create the final executable

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
