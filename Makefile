NAME	= pipex

SRC_PATH = src/
OBJ_PATH = obj/
SRC 	= pipex.c utils.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ 	= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
HEADER = -I include

all: $(NAME)

$(NAME): $(OBJS)
	@make re -C ./libft
	@$(CC) $(OBJS) -L ./libft -lft -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@
	
clean:
		@make clean -C ./libft
		@rm -rf $(OBJ_PATH)

fclean: 	clean
		@make fclean -C ./libft
		@rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
