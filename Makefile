# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 12:25:20 by pnurmi            #+#    #+#              #
#    Updated: 2025/09/02 10:30:24 by pnurmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
NAME        := so_long

# Directory Definitions
SRC_DIR     := src
OBJ_DIR     := objs
INC_DIR     := includes

# Source Files: Manually listed with full paths
SRC        := $(SRC_DIR)/main/main.c \
               $(SRC_DIR)/map/map_parsing.c \
			   $(SRC_DIR)/map/map_checks.c \
               $(SRC_DIR)/map/dimensions.c \
               $(SRC_DIR)/game/hooks.c \
			   $(SRC_DIR)/game/textures.c \
			   $(SRC_DIR)/game/execution.c \
			   $(SRC_DIR)/utility/error.c \
			   $(SRC_DIR)/utility/flood_fill.c \
			   $(SRC_DIR)/parsing/arg_parse.c 

# Header File for so_long
HEADER      := so_long.h

# Object Files: Generated from full source paths
OBJS        := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Compiler and Flags
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g

# Remove Command
RM          := rm -f

# Libft Integration
LIBFT_DIR   := ./libft
LIBFT       := $(LIBFT_DIR)/libft.a
LIBFT_H     := $(LIBFT_DIR)/libft.h

# MinilibX Integration
MLX_DIR     := ./minilibx
MLX_LIB     := $(MLX_DIR)/libmlx.a

# Include Paths and Libraries
INC         := -I. -I$(LIBFT_DIR) -I$(INC_DIR) -I$(MLX_DIR)
LIBS        := -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# For macOS, replace the MLX linking flags with:
# LIBS        := -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# -------------------- Main Targets --------------------

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBS) -o $(NAME)

# Rule to compile individual .c files into .o files.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Rule to build libft.a
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to build MinilibX
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# Rule to create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# -------------------- Phony Targets --------------------

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all