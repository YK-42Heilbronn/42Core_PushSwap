# NAME = push_swap.a
NAME = push_swap

SCRS = utils.c ops.c parser.c push_swap.c
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SCRS:.c=.o)

# no need to link libft seperately already printf object files have it
# LIBFT_DIR = ./libft
# LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

STACK_DIR = ./stack
STACK = $(STACK_DIR)/stack.a

all: $(NAME)

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(STACK):
	@make -C $(STACK_DIR)

$(NAME): $(PRINTF) $(STACK)
# 	LINK: 1
#   NOTE: following command is used to run the specific script
	@cc $(CFLAGS)  $(SCRS) $(PRINTF) $(STACK) -o $(NAME) 

# $(NAME): $(LIBFT) $(STACK) $(OBJ)
# #   NOTE: following commands used to create the static lib of the specific project
# 	@cp $(LIBFT) $(NAME)
# 	@cp $(STACK) $(NAME)
# 	ar rcs $(NAME) $(OBJ)
# 	ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C $(PRINTF_DIR) clean
	@make -C $(STACK_DIR) clean
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean
	@make -C $(STACK_DIR) fclean

re: fclean all

.PHONY: all clean fclean re run

# 	LINK: 1
run:
	@chmod 777 $(NAME)
	@./$(NAME)


