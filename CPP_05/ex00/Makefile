CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

SRC = main.cpp Bureaucrat.cpp

OBJ = $(SRC:%.cpp=%.o)

RM = rm -f

NAME = Bureaucrat

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re