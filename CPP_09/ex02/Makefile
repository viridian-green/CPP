CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98
#FLAGS = -std=c++17

#SRC = PMergeTest.cpp
SRC = main.cpp

OBJ = $(SRC:%.cpp=%.o)

RM = rm -f

NAME = PmergeMe

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJ)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re