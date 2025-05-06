CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

SRC = Animal.cpp Dog.cpp Cat.cpp main.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

OBJ = $(SRC:%.cpp=%.o)

RM = rm -f

NAME = AbstractClass

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re