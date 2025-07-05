NAME := diamondtrap
SRCS := ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp \
		main.cpp
LIBFT_DIR :=
BONUS_SRCS :=
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -g -std=c++98
LFLAGS :=
IFLAGS :=
OBJS := $(SRCS:.cpp=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(IFLAGS) $(LFLAGS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(IFLAGS) -c $< -o $@ 

.PHONY: re
re: fclean all

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: test
test: $(NAME)
	./$(NAME)

.PHONY: leak
leak: $(NAME)
	valgrind --leak-check=full ./$(NAME)
