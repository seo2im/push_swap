NAME = test
SRC = ./lib/*.c ./public/*.c *.c ./checker/*.c
HEADER = -I ./includes/
CC = gcc

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $(NAME) $(SRC) $(HEADER)


fclean : 
	rm -rf $(NAME)