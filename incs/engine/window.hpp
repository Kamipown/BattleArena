#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "defs.hpp"
#include "error.hpp"

namespace	kami
{
	class	c_window
	{
	private:
		static bool			opened;

	protected:
		static SDL_Window	*window;
		static SDL_Renderer	*renderer;

	public:
		static void			open(void);
		static void			close(void);

		static bool			is_open(void);
		static t_point		get_size(void);
		static void			set_size(t_point size);
		
	};
}
