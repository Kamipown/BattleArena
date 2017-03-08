#pragma once

#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "error.hpp"
#include "gfx.hpp"
#include "window.hpp"
#include "screen.hpp"
#include "config.hpp"

namespace kami
{
	struct		s_config
	{
		bool	fullscreen;
	};

	class 		c_engine: public c_gfx, public c_config
	{
	private:
		static void		init_sdl2(void);
		static void		init_sdl2_image(void);
		static void		init_sdl2_ttf(void);
		static void		init_sdl2_mixer(void);

	public:
		static void		init(void);
		static void		quit(void);
		
	};
}
