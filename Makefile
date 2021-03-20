NAME = test
SRC = ./main.c \
		./public/stack/stack.c \
		./public/exec/exec.c \
		./lib/*.c
HEADER = -I ./includes/
CC = gcc

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $(NAME) $(SRC) $(HEADER)


fclean : 
	rm -rf $(NAME)