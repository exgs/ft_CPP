NAME = convert
FLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp Casting.cpp

all : $(NAME)

$(NAME):
	clang++ $(FLAGS) $(SRCS) -o $(NAME)
clean :
	rm -rf $(NAME)
fclean : clean
re: fclean all
