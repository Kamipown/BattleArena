#include "time.hpp"

namespace kami
{
	t_uint	c_time::last_frame = 0;
	t_uint	c_time::ellapsed_time = 0;
	t_uint	c_time::fps = 60;
	t_uint	c_time::frame_duration = 1000 / 60;

	void	c_time::restart(void)
	{
		// c_time::last_frame = SDL_GetTicks();
	}

	void	c_time::update(void)
	{
		c_time::ellapsed_time = SDL_GetTicks() - c_time::last_frame;
		if (c_time::fps && c_time::ellapsed_time < c_time::frame_duration)
			SDL_Delay(c_time::frame_duration - c_time::ellapsed_time);
		c_time::last_frame = SDL_GetTicks();
	}

	void	c_time::manage_lock(void)
	{
		if (c_time::fps < 240)
		{
			c_time::fps += 60;
			c_time::frame_duration = 1000 / c_time::fps;
			std::cout << "Target FPS: " << (t_uint)c_time::fps << std::endl;
		}
		else
		{
			fps = 0;
			c_time::frame_duration = 0;
			std::cout << "Target FPS: max" << std::endl;
		}
	}

	t_uint	c_time::delta_time(void)
	{
		return (c_time::frame_duration ? c_time::frame_duration : c_time::ellapsed_time);
	}

	t_uint	c_time::time(void)
	{
		return (SDL_GetTicks());
	}
}
