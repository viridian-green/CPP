CXX = c++

CXFLAGS = -Wall -Wextra -Werror -std=c++98
#FLAGS = -std=c++17

#SRC = MutantStackTest.cpp
SRC = main.cpp

OBJ = $(SRC:%.cpp=%.o)

RM = rm -f

NAME = btc

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(FCXFLAGSLAGS) -o $(NAME) $(OBJ)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re