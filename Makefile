##
## EPITECH PROJECT, 2017
## 
## File description:
## makefile
##

NAME		= getlineshell

CC		= gcc

MAKE		= make -C

LIB		= -L./lib/C -lmy

SRCS		= src/main.c
SRCS		+= src/getlineshell.c
SRCS		+= src/display_line.c
SRCS		+= src/set_getlineshell.c
SRCS		+= src/builtins.c
SRCS		+= src/shortcuts.c
SRCS		+= src/real_cursor_pos.c
SRCS		+= src/insert_inline.c
SRCS		+= src/arrow.c

OBJ		= $(SRCS:.c=.o)

RM		= rm -f

CFLAGS		= -W -Werror -g3 -Wall -Wextra -I ./include

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) lib/C > /dev/null
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)
	@       tput setaf 2; cat include/signature; tput sgr0

clean:
	$(MAKE) lib/C clean > /dev/null
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) lib/C fclean > /dev/null
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
