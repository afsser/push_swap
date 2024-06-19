NAME		:= push_swap
CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror -g3
BIN			:= ./bin/
SRCS		:= $(addprefix ./src/, main.c move.c sort.c utils.c)
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
	@echo "-------------------------------------------------------------------------------------------------"
	@echo "For manual testing, run the program with a list of numbers as arguments, like in this example:"
	@echo "./push_swap 1 2 3 4 5 6 7 8 9 10"
	@echo "Numbers can be negative, but duplicates are NOT allowed"
	@echo "-------------------------------------------------------------------------------------------------"
	@echo "To test the program with 10 random numbers, run 'make test'"
	@echo "To test the program with a specific number of random numbers, run 'make test size=number'"
	@echo "-------------------------------------------------------------------------------------------------"

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

OS = $(shell uname)

size ?= 10

ifeq ($(OS),Linux)
CHECKER = valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)
else
CHECKER = ./push_swap $(ARG) | ./checker_Mac $(ARG)
endif

test:
	@$(eval ARG = $(shell seq -1000 1000 | shuf -n $(size)))
	@echo "Checker result: "
	$(CHECKER)
	@echo "Instructions count: "
	@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re