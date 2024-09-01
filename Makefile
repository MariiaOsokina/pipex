MANE	= pipex
CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
SRC_PATH = src/
OBJ_PATH = obj/

SRC 	= pipex.c utils.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ 	= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

all: 		$(OBJ_PATH) $(NAME)

# .c.o:
# 	${CC} -c $< -o $(<:.c=.o)
$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME):	$(OBJS)
		@make re -C ./libft
		@$(CC) $(CFLAGS) $(OBJS) -L ./libft -lft -o $(NAME)

clean:
		@make clean -C ./libft
		@rm -f $(OBJS)

fclean: 	clean
		@make fclean -C ./libft
		@rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
