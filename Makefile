NAME = cub3d

#############################################

#############################################

SRC_DIR     := srcs
OBJ_DIR     := obj

SRCS := main.c								\
		parsing/check_extension.c			\
		parsing/parse_map.c					\
		parsing/parse_texture.c				\
		parsing/parsing.c					\
		parsing/read_input.c				\
		utils/gnl/get_next_line.c			\
		utils/libft/ft_strdup.c				\
		utils/libft/split.c					\
		utils/libft/libft_utils.c			\
		utils/debug_function.c				\
		utils/error_management.c			\

#############################################

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#############################################

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
CPPFLAGS    := -I inc

#############################################

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

#############################################

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -L/usr/local/lib -I/usr/local/inc -lreadline
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#############################################

.PHONY: all clean fclean re
.SILENT: