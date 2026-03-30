SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD

NAME = Bureaucrat

DEPS = $(OBJ:.o=.d)

all:	$(NAME)

$(NAME):	$(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o:	%.cpp
	c++ $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJ) $(DEPS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all