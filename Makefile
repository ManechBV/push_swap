SRCS = srcs/main.c \
		srcs/lst.c \
		srcs/parsing.c \
		srcs/vars.c \
		srcs/swap.c \
		srcs/push.c \
		srcs/rotate.c \
		srcs/reverse_rotate.c \
		srcs/ft_radix.c
OBJS = $(SRCS:srcs/%.c=objs/%.o)
CC = cc
FLAGS = -Wall -Wextra -Werror -g
NAME = push_swap.exe
INCLUDE_DIRS = -I includes -I libft -I ft_printf

all: objs libft ft_printf $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(OBJS) libft/libft.a ft_printf/libftprintf.a $(INCLUDE_DIRS) -o $(NAME)

$(OBJS): objs/%.o: srcs/%.c
	$(CC) $(FLAGS) $(INCLUDE_DIRS) -c $< -o $@

objs:
	mkdir objs

libft:
	make -C libft

ft_printf:
	make -C ft_printf

re: fclean all

clean:
	rm -rf $(OBJS)
	make clean -C libft
	make clean -C ft_printf

fclean:
	rm -rf $(NAME)
	make fclean -C libft
	make fclean -C ft_printf

.PHONY: all re clean fclean libft ft_printf
