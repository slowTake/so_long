NAME		= libft.a

# Source directories
CHAR_DIR	= src/character
STR_DIR		= src/string
MEM_DIR		= src/memory
NUM_DIR		= src/numeric
IO_DIR		= src/io
PRINTF_DIR	= src/printf
GNL_DIR		= src/gnl

SRCS		= $(CHAR_DIR)/ft_isalpha.c \
			  $(CHAR_DIR)/ft_isdigit.c \
			  $(CHAR_DIR)/ft_isalnum.c \
			  $(CHAR_DIR)/ft_isascii.c \
			  $(CHAR_DIR)/ft_isprint.c \
			  $(CHAR_DIR)/ft_toupper.c \
			  $(CHAR_DIR)/ft_tolower.c \
			  $(STR_DIR)/ft_strlen.c \
			  $(STR_DIR)/ft_strlcpy.c \
			  $(STR_DIR)/ft_strlcat.c \
			  $(STR_DIR)/ft_strchr.c \
			  $(STR_DIR)/ft_strrchr.c \
			  $(STR_DIR)/ft_strncmp.c \
			  $(STR_DIR)/ft_strnstr.c \
			  $(STR_DIR)/ft_strdup.c \
			  $(STR_DIR)/ft_substr.c \
			  $(STR_DIR)/ft_strjoin.c \
			  $(STR_DIR)/ft_strtrim.c \
			  $(STR_DIR)/ft_split.c \
			  $(STR_DIR)/ft_strmapi.c \
			  $(STR_DIR)/ft_striteri.c \
			  $(MEM_DIR)/ft_memset.c \
			  $(MEM_DIR)/ft_bzero.c \
			  $(MEM_DIR)/ft_memcpy.c \
			  $(MEM_DIR)/ft_memmove.c \
			  $(MEM_DIR)/ft_memchr.c \
			  $(MEM_DIR)/ft_memcmp.c \
			  $(MEM_DIR)/ft_calloc.c \
			  $(NUM_DIR)/ft_atoi.c \
			  $(NUM_DIR)/ft_itoa.c \
			  $(IO_DIR)/ft_putchar_fd.c \
			  $(IO_DIR)/ft_putstr_fd.c \
			  $(IO_DIR)/ft_putendl_fd.c \
			  $(IO_DIR)/ft_putnbr_fd.c \
			  $(PRINTF_DIR)/ft_printf.c \
			  $(PRINTF_DIR)/ft_printf_utility.c \
			  $(GNL_DIR)/ft_gnl.c \
			  $(GNL_DIR)/ft_gnl_util.c

# Object files directory
OBJ_DIR		= objs

# Object files - all go to objs/ folder
OBJS		= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# Compiler and Flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.

# Archive command
AR			= ar -rcs

# Remove command
RM			= rm -f

# -------------------- Main Targets --------------------

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Create objs directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# vpath tells make where to look for source files
vpath %.c $(CHAR_DIR)
vpath %.c $(STR_DIR)
vpath %.c $(MEM_DIR)
vpath %.c $(NUM_DIR)
vpath %.c $(IO_DIR)
vpath %.c $(PRINTF_DIR)
vpath %.c $(GNL_DIR)

# Compilation rule
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# -------------------- Phony Targets --------------------

.PHONY: all clean fclean re

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_DIR)

re: fclean all