NAME = do-op

SRC := ft_atoi.c main.c ops.c print.c
OBJ := $(SRC:.c=.o)

CC := cc

CPPFLAGS :=
CFLAGS := -Wall -Wextra -Werror -pedantic
LDFLAGS :=

ifdef DEBUG
	CC := clang
	CFLAGS += -g3 -Og -fsanitize=undefined
	LDFLAGS += -fsanitize=undefined
else
	CFLAGS += -O3 -g0 -flto
	LDFLAGS += -flto
endif

ifdef ASAN
	CFLAGS += -fsanitize=address
	LDFLAGS += -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -- $(OBJ)

fclean: clean
	$(RM) -- $(NAME)

re: fclean all

norm:
	norminette $(SRC) *.h

debug:
	@$(MAKE) DEBUG=1 re

asan:
	@$(MAKE) DEBUG=1 ASAN=1 re

tests: debug
	./do-op
	./do-op 1 + 1
	./do-op 42amis - --+-20toto12
	./do-op 1 p 1
	./do-op 1 + toto3
	./do-op toto3 + 4
	./do-op foo plus bar
	./do-op 25 / 0
	./do-op 25 % 0

.PHONY: all asan clean debug fclean norm re tests
