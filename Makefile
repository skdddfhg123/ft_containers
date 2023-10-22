CC = c++
CFLAGS =-Wall -Wextra -Werror -std=c++98
NAME = test
SRCS = main.cpp
OBJ = $(SRCS:.cpp=.o)
HEADER = ./includes

all: ${NAME}

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $^ -o $@ -I$(HEADER)

clean:
	@rm -rf $(OBJ)

fclean:
	@make clean
	@rm -rf ${NAME}

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
