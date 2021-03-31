NAME = Replace
FLAGS = -Wall -Werror -Wextra -std=c++98
COMPILER = clang++
SRCS = Replace.cpp utils.cpp

all: $(NAME)

$(NAME):
	$(COMPILER) $(FLAGS) $(SRCS) -o $(NAME)
clean:
	rm -rf ./Replace
fclean: clean
re: fclean all
