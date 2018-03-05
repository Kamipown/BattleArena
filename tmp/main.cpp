#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>

int		main(int argc, char **argv)
{
	std::cout << SDL_Init(SDL_INIT_VIDEO) << std::endl;
	// if (SDL_Init(SDL_INIT_VIDEO) != 0)
	// 	std::cerr << "[1] Can't initialize SDL2." << std::endl;
	// if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
	// 	std::cerr << "[2] Can't initialize SDL2_image." << std::endl;
	// if (TTF_Init() == -1)
	// 	std::cerr << "[3] Can't initialize SDL2_ttf." << std::endl;
	// if (0)
	// 	std::cerr << "[4] Can't initialize SDL2_mixer." << std::endl;
}
