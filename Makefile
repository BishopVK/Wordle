# Colors definition
COLOR_CYAN := "\033[36m"
COLOR_GREEN := "\033[32m"
COLOR_RESET := "\033[0m"

# Macro to print a message in cyan color
define print_cyan
	@echo $(COLOR_CYAN)$1$(COLOR_RESET)
endef

# Macro to print a message in green color
define print_green
	@echo $(COLOR_GREEN)$1$(COLOR_RESET)
endef

NAME			=	wordle

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3
READFLAG		=	-lreadline

SRC_DIR			=	src
SRC				=	$(SRC_DIR)/main.c \
					$(SRC_DIR)/parse.c \
					$(SRC_DIR)/game_logic.c

OBJ				=	$(SRC:.c=.o)

LIBFT_DIR	=	include/libft
LIBFT		=	$(LIBFT_DIR)/libft.a

all: $(NAME)

r: all clean
	./$(NAME)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) $(OBJ) $(LIBFT) $(READFLAG) -o $(NAME)
	$(call print_cyan, "Compiled wordle")

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	$(call print_green, "Cleaned wordle objects")

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	$(call print_green, "Cleaned the library libft.a")
	$(call print_green, "Cleaned wordle executable")

re: fclean all

.PHONY: all clean fclean re