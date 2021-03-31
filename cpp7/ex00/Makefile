NAME = whatever
FALGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp

all: $(NAME)

$(NAME) :
	clang++ $(FALGS) $(SRCS) -o $(NAME)

clean :
	rm -rf $(NAME)
fclean : clean
re : fclean all
