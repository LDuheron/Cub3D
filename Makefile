NAME = cub3d

YELLOW := "\e[0;33m"
PINK := "\e[0;95m"

#############################################

#############################################

SRC_DIR     := srcs
OBJ_DIR     := obj

SRCS := main.c								\
		parsing/first_reading.c				\
		parsing/is_surrounded_by_walls.c	\
		parsing/is_valid.c					\
		parsing/parse_map.c					\
		parsing/parse_texture.c				\
		parsing/parsing.c					\
		parsing/read_input_file.c			\
		utils/gnl/get_next_line.c			\
		utils/libft/ft_atoi.c				\
		utils/libft/ft_calloc.c				\
		utils/libft/ft_strdup.c				\
		utils/libft/ft_substr.c				\
		utils/libft/split.c					\
		utils/libft/libft_utils.c			\
		utils/debug_function.c				\
		utils/error_management.c			\
		utils/is_something.c				\
		window/create_window.c				\
		window/draw_map.c					\
		window/draw_utils.c					\
		window/events.c						\
		window/ft_unstrlen.c				\
		window/raycasting.c					\

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
MLX = make -C ./mlx

#############################################

all: $(NAME)

$(NAME): $(OBJS)
	$(MLX)
	$(CC) $(OBJS) -o $(NAME) -L/usr/local/lib -I/usr/local/inc -lreadline -L./mlx -lmlx -lXext -lX11 -lm
	@echo $(YELLOW)"$$KEY" $(RESET)
	@echo $(PINK)"$$TITLE" $(RESET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	@cd ./mlx && make clean

re:
	$(MAKE) fclean
	$(MAKE) all

#############################################

.PHONY: all clean fclean re
.SILENT:

info : game_init

define KEY

    .---.
   /    |\________________
  ( ()  | ________   _   _)
   \    |/        | | | |
    `---'         "-" |_|

endef
export KEY

define TITLE

- THE GRAND BUDAPEST HOTEL -

endef
export TITLE

define HOUSE_INIT

   ~6_.___,`P_,`P_,`P_,`P                                     |
 *  |___)  /^\ /^\ /^\ /^\      *         *   ,     *        \   /
    ='='=`    *                      *        )            --  *   --
                   *           .-----------. ((              /   \
        *                *     )`'`'`'`'`'`( ||     *          |
                              /`'`'`'`'`'`'`\||                     *
    *         *      *       /`'`'`'`'`'`'`'`\| *        *
                    ,,,,,,, /`'`'`'`'`'`'`'`'`\      ,
       *           .-------.`|```````````````|`  .   )       *    *
   *        *     / ,^, ,^, \|  ,^^,   ,^^,  |  / \ ((
                 /  |_| |_|  \  |__|   |__|  | /   \||   *
    *       *   /_____________\ |  |   |  |  |/     \|           *
                 |  __   __  |  '=='   '=='  /.......\     *
  *     *        | (  ) (  ) |  //`_```_`\\  |,^, ,^,|     _    *
   ___,.,___     | |--| |--| |  ||(O)|(O)||  ||_| |_||   _|-|_
  (  (("))  ) *  | |__| |__| |  || " | " ||  ||_| |_|| *  (")       *
   \_('@')_/     |           |  ||   |   ||  |       |  --(_)--  *
 ***/_____\******'==========='==''==='===''=='======='***(___)*****ldb

endef
export HOUSE_INIT