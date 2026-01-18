SRC = main.cpp Bureaucrat.cpp Form.cpp

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = Bureaucrat

all:	$(NAME)

$(NAME):	$(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o:	%.cpp Bureaucrat.hpp Form.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all