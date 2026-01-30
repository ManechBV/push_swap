SRCS = srcs/main.c \
		srcs/lst.c \
		srcs/parsing.c \
		srcs/vars.c
OBJS = $(SRCS:srcs/%.c=objs/%.o)
CC = cc
FLAGS = -Wall -Wextra -Werror 
NAME = push_swap.exe
INCLUDE_DIRS = -I includes -I libft

all: objs libft $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(OBJS) libft/libft.a $(INCLUDE_DIRS) -o $(NAME)

$(OBJS): objs/%.o: srcs/%.c
	$(CC) $(FLAGS) $(INCLUDE_DIRS) -c $< -o $@

objs:
	mkdir objs

libft:
	make -C libft

re: fclean all

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean:
	rm -rf $(NAME)
	make fclean -C libft

.PHONY: all re clean fclean libft
