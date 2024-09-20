NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/
RM = rm -f

LIBFT = ./libft/libft.a

SRCS = main.c move.c parsing.c setup.c sort.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT): 
	$(MAKE) -C ./libft

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -c ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re