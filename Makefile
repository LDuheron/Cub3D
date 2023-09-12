NAME = cub3d

SOURCES = ./src/main.c	\

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

OBJETS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJETS)
		$(CC) $(CFLAGS) $(OBJETS) -o $(NAME)

clean:
		@rm -f $(OBJETS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: