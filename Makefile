NAME =	game

CC =	g++

FLG =	-Wall -Wextra -Werror -pg -g

LIB =	-lSDL2 -lSDL2_image -lSDL2_ttf

INC =	-I./incs -I./incs/game -I./incs/engine

SRC =	srcs/main.cpp srcs/game/*.cpp srcs/engine/*.cpp

OBJ =	main.o game.o engine.o

all: $(NAME)

$(NAME):
	# g++ -Wall -Wextra -Werror srcs/main.cpp -lSDL2 -lSDL2_image -lSDL2_ttf
	$(CC) $(FLG) $(SRC) $(INC) $(LIB) -o $(NAME)
	# $(CC) -O3 -o $(NAME) $(OBJ)

libkami:
	make -C kami/ re

clean:
	rm -f $(OBJ)
	rm -f profiling.out
	rm -f gmon.out

fclean: clean
	rm -f $(NAME)

re: fclean all

rex: re
	./$(NAME)

profiling:
	gprof $(NAME) > profiling.out
