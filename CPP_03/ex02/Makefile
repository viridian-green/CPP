CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp

OBJ = $(SRC:%.cpp=%.o)

RM = rm -f

NAME = FragTrap

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re