NAME = libft.a

INCLUDE_DIR = includes
SRC_DIR = srcs

CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I$(INCLUDE_DIR)

SRC = $(addprefix $(SRC_DIR)/, ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c)
OBJ = $(SRC:.c=.o)

AR ?= ar
RM ?= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs -- $@ $^

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -- $(OBJ)

fclean: clean
	$(RM) -- $(NAME)

re: fclean all

.PHONY: all clean fclean re
