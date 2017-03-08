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
		for (t_uint i = 0; i < c_screen::modes.size(); ++i)
			std::cout << c_screen::modes[i].w << " " << c_screen::modes[i].h << " " << c_screen::modes[i].refresh_rate << std::endl;
		for (t_uint8 i = 0; i < 10; ++i)
			std::cout << 320 * i << " " << 240 * i << std::endl;
	}

	void		c_screen::save(void)
	{
		
	}
}
