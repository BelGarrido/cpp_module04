
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = animal

SRC = main.cpp \
	animal.cpp \
	cat.cpp \
	dog.cpp \
	brain.cpp 

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re