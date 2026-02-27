NAME = push_swap

SCRS = 1_parsing/clean_and_prepare.c 1_parsing/compute_count.c \
		2_stack/stack_init.c 2_stack/stack_ops_basic.c \
		3_algo/index_normalize.c 3_algo/radix_sort.c 3_algo/small_sort.c \
		4_utils/error.c 4_utils/str_mans.c \
		push_swap.c
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SCRS:.c=.o)

# no need to link libft seperately already printf object files have it
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT)
	@cc $(CFLAGS)  $(SCRS) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
