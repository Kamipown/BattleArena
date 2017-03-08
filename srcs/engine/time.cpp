#include "time.hpp"

namespace kami
{
	t_uint	c_time::last_frame;
	t_uint	c_time::ellapsed_time;

	void	c_time::restart(void)
	{
		c_time::last_frame = SDL_GetTicks();
	}

	void	c_time::update(void)
	{
		c_time::ellapsed_time = SDL_GetTicks() - c_time::last_frame;
		// std::cout << c_time::ellapsed_time << std::endl;
		// if (c_time::ellapsed_time < 5)
		// 	SDL_Delay(5 - c_time::ellapsed_time);
		c_time::last_frame = SDL_GetTicks();
		SDL_Delay(5);
	}

	t_uint	c_time::delta_time(void)
	{
		return (c_time::ellapsed_time);
	}
}
