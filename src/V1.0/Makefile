# NAME = push_swap.a
NAME = push_swap

SCRS = parsing/clean_and_prepare.c parsing/compute_count.c \
		stack/stack_init.c stack/stack_ops_basic.c \
		algo/index_normalize.c algo/radix_sort.c algo/small_sort.c \
		utils/error.c utils/str_mans.c \
		main.c
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SCRS:.c=.o)

# no need to link libft seperately already printf object files have it
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# PRINTF_DIR = ./printf
# PRINTF = $(PRINTF_DIR)/libftprintf.a

# STACK_DIR = ./stack
# STACK = $(STACK_DIR)/stack.a

all: $(NAME)

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

# $(PRINTF):
# 	@make -C $(PRINTF_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

# $(STACK):
# 	@make -C $(STACK_DIR)

$(NAME): $(LIBFT)
# 	LINK: 1
#   NOTE: following command is used to run the specific script
	@cc $(CFLAGS)  $(SCRS) $(LIBFT) -o $(NAME)

# $(NAME): $(LIBFT) $(STACK) $(OBJ)
# #   NOTE: following commands used to create the static lib of the specific project
# 	@cp $(LIBFT) $(NAME)
# 	@cp $(STACK) $(NAME)
# 	ar rcs $(NAME) $(OBJ)
# 	ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re run

# 	LINK: 1
run:
	@chmod 777 $(NAME)
	@./$(NAME)

