NAME		:= push_swap
CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror -g3
BIN			:= ./bin/
SRCS		:= $(addprefix ./src/,\
main.c sort.c utils.c args.c errors.c\
moves_push.c moves_rotate.c moves_reverse_rotate.c moves_swap.c\
push_swap.c stack_utils.c)
OBJS		:= $(patsubst ./src/%.c,$(BIN)%.o,$(SRCS))
LIB			:= ./libft/libft.a
HEADERS		:= -I ./include/mandatory/push_swap.h -I ./libft

all: libft/libft.a $(BIN) $(NAME)

libft/libft.a:
	@make -sC ./libft 

$(BIN)%.o: ./src/%.c
	@$(CC) $(FLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIB) $(HEADERS) -o $(NAME)
	@echo "[ COMPILATION COMPLETE !!! ]"

$(BIN):
	@mkdir -p $(BIN)

clean:
	@rm -rf $(BIN)
	@make clean -sC ./libft

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ./libft/libft.a
	@echo "[ CLEANED ]"

re: fclean all

.PHONY: all clean fclean re