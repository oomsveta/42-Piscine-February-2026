NAME := bsq

INCLUDE_DIR := include
BUILD_DIR := build
SRC_DIR := src
LIBFT_DIR := libft

SRC_FILES := main.c parser.c solver.c bsq_utils.c
SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
DEP := $(OBJ:.o=.d)
LIBFT := $(LIBFT_DIR)/libft.a

CC := cc

CPPFLAGS := -MMD -MP -I$(LIBFT_DIR) -I$(INCLUDE_DIR)
CFLAGS := -Wall -Wextra -Werror
LDFLAGS := -L$(LIBFT_DIR)
LDLIBS := -lft

ifdef DEBUG
	CC := clang
	CFLAGS += -g3 -Og -fsanitize=undefined
	LDFLAGS += -fsanitize=undefined
else
	CFLAGS += -g0
endif

ifdef ASAN
	CFLAGS += -fsanitize=address
	LDFLAGS += -fsanitize=address
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@

$(LIBFT): $(LIBFT_DIR)/Makefile
	@$(MAKE) -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p -- $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r -- $(BUILD_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) -- $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

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
