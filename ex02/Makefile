SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD

DEPS = $(OBJ:.o=.d)

NAME = Bureaucrat

all:	$(NAME)

$(NAME):	$(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o:	%.cpp
	c++ $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all