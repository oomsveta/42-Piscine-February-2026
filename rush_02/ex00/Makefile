NAME := rush-02

INCLUDE_DIR := include
BUILD_DIR := build
SRC_DIR := src

SRC_FILES := main.c repl.c next_triad.c number_to_words.c validate_number.c get_words.c print_sub_100.c \
			$(addprefix utils/, substr_to_uint.c ft_memcpy.c ft_strndup.c ft_strspn.c ft_strlen.c ft_memchr.c ft_memmove.c ft_strchr.c ft_strcspn.c ft_strnlen.c ft_zmax.c ft_strcmp.c ft_streq.c ft_isdigit.c ft_putstr.c ft_atoi.c puterr.c) \
			$(addprefix lst/, lst_create_node.c lst_prepend.c lst_at.c lst_find.c lst_free.c) \
			$(addprefix dict/, cmp_fns.c free_fns.c check_dict.c) \
			$(addprefix parsing/, read_line.c parse_checks.c parser.c)
SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
DEP := $(OBJ:.o=.d)

CC := cc

CPPFLAGS := -MMD -MP -I$(INCLUDE_DIR)
CFLAGS := -Wall -Wextra -Werror
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

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p -- $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r -- $(BUILD_DIR)

fclean: clean
	$(RM) -- $(NAME)

re: fclean all

norm:
	norminette $(SRC) *.h

debug:
	@$(MAKE) DEBUG=1 re

asan:
	@$(MAKE) DEBUG=1 ASAN=1 re

compile_commands.json: fclean
	bear -- $(MAKE) all

-include $(DEP)

.PHONY: all asan clean debug fclean norm re tests
