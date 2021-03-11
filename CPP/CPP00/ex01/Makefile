NAME = phonebook
FLAG = -Wall -Werror -Wextra -std=c++98
SRCS = member.cpp main.cpp

all : $(NAME)

$(NAME):
	clang++ $(FLAG) $(SRCS) -o $(NAME)
clean :
	rm -rf $(NAME)
fclean : clean
re: fclean all
