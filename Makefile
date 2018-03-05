NAME =	game

CC =	g++

FLG =	-Wall -Wextra -Werror

LIB =	-lSDL2 -lSDL2_image -lSDL2_mixer  -lSDL2_ttf

INC =	-I./inc

SRC =	src/*.cpp

# OBJ =	main.o game.o engine.o

all: $(NAME)

$(NAME):
	$(CC) -O3 $(FLG) $(SRC) $(INC) $(LIB) -o out/$(NAME)
	# $(CC) -O3 $(FLG) $(SRC) $(INC) -o out/$(NAME)

clean:
	rm -f out/$(NAME)
	# rm -f $(OBJ)
	# rm -f profiling.out
	# rm -f gmon.out

re: clean all

rex: re
	./$(NAME)
