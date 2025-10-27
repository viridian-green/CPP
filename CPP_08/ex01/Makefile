CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98
# FLAGS = -std=c++17

# SRC = SpanTest.cpp
SRC = main1.cpp

OBJ = $(SRC:%.cpp=%.o)

RM = rm -f

NAME = span

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJ)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re