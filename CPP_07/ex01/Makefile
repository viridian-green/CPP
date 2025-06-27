CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

SRC := $(addprefix src/, $(SRC))

OBJ = $(SRC:%.cpp=%.o)

RM = rm -f

NAME = iter

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJ)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re