NAME = push_swap.a

SCRS = utils.c ops.c
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SCRS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

STACK_DIR = ./stack
STACK = $(STACK_DIR)/stack.a

all: $(NAME)

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(STACK):
	@make -C $(STACK_DIR)

# $(NAME): $(LIBFT)
# # 	LINK: 1
# #   NOTE: following command is used to run the specific script
# 	@cc $(CFLAGS)  $(SCRS) $(LIBFT) -o $(NAME) 

$(NAME): $(LIBFT) $(STACK) $(OBJ)
#   NOTE: following commands used to create the static lib of the specific project
	@cp $(LIBFT) $(NAME)
	@cp $(STACK) $(NAME)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@make -C $(STACK_DIR) clean
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(STACK_DIR) fclean

re: fclean all

.PHONY: all clean fclean re run

# # 	LINK: 1
# run:
# 	@chmod 777 $(NAME)
# 	@./$(NAME)


