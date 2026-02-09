NAME = ft_cat

INCLUDE_DIR := include
BUILD_DIR := build
SRC_DIR := src

SRC_FILES := main.c ft_strcmp.c ft_strlen.c
SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
DEP := $(OBJ:.o=.d)

CC := cc

CPPFLAGS := -MMD -MP -I$(INCLUDE_DIR)
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

.PHONY: all asan clean debug fclean fclean norm re tests
