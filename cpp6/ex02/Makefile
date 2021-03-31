NAME = a.out
FLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp Base.cpp

all : $(NAME)

$(NAME):
	clang++ $(FLAGS) $(SRCS) -o $(NAME)
clean :
	rm -rf $(NAME)
fclean : clean
re: fclean all
