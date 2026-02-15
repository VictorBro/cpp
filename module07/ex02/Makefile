NAME := array
SRCS := main.cpp
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -g -std=c++98
OBJS := $(SRCS:.cpp=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: re
re: fclean all

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: leak
leak: $(NAME)
	valgrind --leak-check=full ./$(NAME)
