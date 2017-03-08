#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "defs.hpp"
#include "error.hpp"

namespace kami
{
	class 		c_screen
	{
	private:
		static std::vector<SDL_DisplayMode>	modes;

	protected:
		static void		init(void);
		static t_point	get_best_windowed_size(void);
		static void		save(void);

	public:
		
	};
}
