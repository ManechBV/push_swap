SRCS = srcs/main.c 
OBJS = $(SRCS:srcs/%.c=objs/%.o)
CC = cc
FLAGS = -Wall -Wextra -Werror 
NAME = solong
INCLUDE_DIRS = -I includes

all: $(NAME)

$(NAME): ft_printf $(OBJS) 
	$(CC) $(OBJS) $(INCLUDE_DIRS) -o $(NAME)

$(OBJS): objs/%.o: srcs/%.c
	$(CC) $(FLAGS) $(INCLUDE_DIRS) -c $< -o $@


re: fclean all

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME)

.PHONY: all re clean fclean 
