#pragma once

#include <SDL2/SDL.h>

#include "defs.hpp"
#include "gfx.hpp"
#include "window.hpp"

namespace	kami
{
	enum	e_directions {top, right, left, down};

	class	c_event : public c_gfx
	{
	private:
		static SDL_Event	event;

		static void			reset(void);
		static bool			update_keyboard(void);
		static bool			update_mouse(void);
		static bool			update_window(void);

	public:
		static void			update(void);

		static bool			quit;
		static bool			escape;
		static bool			arrows[4];
		static bool			keyboard_1;
		static bool			keyboard_2;
		static bool			keyboard_3;
		static bool			mouse_left;
		static t_point		mouse_click;
		
	};
}
