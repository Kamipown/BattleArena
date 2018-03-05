#include "screen.hpp"

namespace kami
{
	std::vector<SDL_DisplayMode>	c_screen::modes;

	void		c_screen::init(void)
	{
		SDL_DisplayMode	mode;
		t_uint			modes_count;

		if (SDL_GetNumVideoDisplays() < 1)
			c_error::set(5, "No video display.");
		modes_count = SDL_GetNumDisplayModes(0);
		for (; modes_count > 0; --modes_count)
		{
			SDL_GetDisplayMode(0, modes_count - 1, &mode);
			c_screen::modes.push_back(mode);
		}
	}

	t_point		c_screen::get_best_windowed_size(void)
	{
		t_uint8	scale = 1;
		t_point	size = (t_point){320, 240};

		while (320 * scale < c_screen::modes[c_screen::modes.size() - 1].w && 240 * scale < c_screen::modes[c_screen::modes.size() - 1].h)
			++scale;
		return ((t_point){size.x * (scale - 1), size.y * (scale - 1)});
	}

	void		c_screen::save(void)
	{
		
	}
}
