NAME = megaphone
FLAG = -Wall -Werror -Wextra -std=c++98
SRCS = megaphone.cpp

all : $(NAME)

$(NAME):
	clang++ $(FLAG) $(SRCS) -o $(NAME)
clean :
	rm -rf megaphone
fclean: clean
re: fclean all
