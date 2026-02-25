NAME = libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -MMD -MP

ifdef DEBUG
    CC := clang
    CFLAGS += -g3 -Og -fsanitize=undefined
else
    CFLAGS += -g0
endif

ifdef ASAN
	CFLAGS += -fsanitize=address
endif

SRC := ft_memchr.c ft_memcpy.c ft_puts.c ft_strlen.c ft_umin.c ft_realloc.c ft_isprint.c ft_malloc.c
OBJ := $(SRC:.c=.o)
DEP := $(OBJ:.o=.d)

AR ?= ar

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -- $(OBJ) $(DEP)

fclean: clean
	$(RM) -- $(NAME)

re: fclean all

norm:
	norminette $(SRC) *.h

-include $(DEP)

.PHONY: all clean fclean re norm
