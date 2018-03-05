#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "defs.hpp"
#include "error.hpp"
#include "screen.hpp"

namespace	kami
{
	class	c_window: public c_screen
	{
	private:
		static bool			opened;

	protected:
		static SDL_Window	*window;
		static SDL_Renderer	*renderer;

		static void			init(void);
		
	public:
		static void			close(void);

		static bool			is_open(void);
		static t_point		get_size(void);
		static void			set_size(t_point size);
		
	};
}
