#pragma once

#include <SDL2/SDL.h>

#include "defs.hpp"
#include "window.hpp"

namespace	kami
{
	class	c_event
	{
	private:
		static SDL_Event	event;

		static void			reset(void);

	public:
		static void			update(void);

		static bool			quit;
		static bool			escape;
		static bool			keyboard_1;
		static bool			keyboard_2;
		static bool			keyboard_3;
		static bool			mouse_left;
		static t_point		mouse_click;
		
	};
}
