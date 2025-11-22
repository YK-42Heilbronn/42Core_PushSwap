NAME = stack.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = stack.c ops.c

OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:	
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME) 

re: clean fclean all

.PHONY: all clean fclean re


