NAME := convert
SRCS := ScalarConverter.cpp \
		main.cpp
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

# online float conversion: https://www.h-schmidt.net/FloatConverter/IEEE754.html
.PHONY: test
test: $(NAME)
	@echo "--- char ---"
	./$(NAME) "'a'"
	@echo ""
	./$(NAME) "'0'"
	@echo ""
	@echo "--- int ---"
	./$(NAME) 0
	@echo ""
	./$(NAME) -42
	@echo ""
	./$(NAME) 42
	@echo ""
	@echo "--- float ---"
	./$(NAME) 0.0f
	@echo ""
	./$(NAME) -4.2f
	@echo ""
	./$(NAME) 42.0f
	@echo ""
	@echo "--- double ---"
	./$(NAME) 0.0
	@echo ""
	./$(NAME) -4.2
	@echo ""
	./$(NAME) 42.0
	@echo ""
	@echo "--- pseudo ---"
	./$(NAME) nan
	@echo ""
	./$(NAME) nanf
	@echo ""
	./$(NAME) +inf
	@echo ""
	./$(NAME) -inf
	@echo ""
	./$(NAME) +inff
	@echo ""
	./$(NAME) -inff
	@echo ""
	@echo "--- edge cases ---"
	./$(NAME) 2147483647
	@echo ""
	./$(NAME) -2147483648
	@echo ""
	./$(NAME) 2147483648
	@echo ""
	./$(NAME) invalid
	@echo ""
	./$(NAME) "'*'"
	@echo ""
	@echo "--- tricky inputs ---"
	./$(NAME) ""
	@echo ""
	./$(NAME) "  42"
	@echo ""
	./$(NAME) "42 "
	@echo ""
	./$(NAME) "+"
	@echo ""
	./$(NAME) "."
	@echo ""
	./$(NAME) ".5"
	@echo ""
	./$(NAME) "5."

.PHONY: leak
leak: $(NAME)
	valgrind --leak-check=full ./$(NAME) 42
