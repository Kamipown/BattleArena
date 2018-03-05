NAME =	game

CC =	g++

FLG =	-Wall -Wextra -Werror
DFLG =	-g -pg

LIB =	-lSDL2 -lSDL2_image -lSDL2_ttf

INC =	-I./inc -I./inc/game -I./inc/engine

SRC =	src/main.cpp
# src/game/*.cpp src/engine/*.cpp

OBJ =	main.o game.o engine.o

all: $(NAME)

$(NAME):
	# g++ -Wall -Wextra -Werror src/main.cpp -lSDL2 -lSDL2_image -lSDL2_ttf
	# $(CC) -O3 $(FLG) $(SRC) $(INC) $(LIB) -o $(NAME)
	# $(CC) -O3 -o $(NAME) $(OBJ)

clean:
	rm -f out/$(NAME)
	# rm -f $(OBJ)
	# rm -f profiling.out
	# rm -f gmon.out

re: clean all

rex: re
	./$(NAME)

profiling:
	gprof $(NAME) > profiling.out
