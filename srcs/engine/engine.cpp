#include "engine.hpp"

namespace kami
{
	void		c_engine::init_sdl2(void)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
			c_error::set(1, "Can't initialize SDL2.");
	}

	void		c_engine::init_sdl2_image(void)
	{
		if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
			c_error::set(2, "Can't initialize SDL2_image.");
	}

	void		c_engine::init_sdl2_ttf(void)
	{
		if (TTF_Init() == -1)
			c_error::set(3, "Can't initialize SDL2_ttf.");
	}

	void		c_engine::init_sdl2_mixer(void)
	{
		if (0)
			c_error::set(4, "Can't initialize SDL2_mixer.");
	}

	void		c_engine::init(void)
	{
		c_engine::init_sdl2();
		c_engine::init_sdl2_image();
		c_engine::init_sdl2_ttf();
		c_engine::init_sdl2_mixer();

		c_screen::init();
		c_config::init();
		c_window::init();
		c_gfx::init();
	}

	void		c_engine::quit(void)
	{
		c_config::save();

		// MIX_Quit();
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
	}
}
