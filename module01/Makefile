NAME	:=	Relationship

SRC	:=	$(wildcard ex00/*.cpp)

OBJ := $(SRC:.cpp=.o)

CC	:=	c++

CFLAGS	:= -Wall -Wextra -Werror -std=c++20 -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $(NAME) -g -fsanitize=address

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re