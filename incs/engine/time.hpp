#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include "defs.hpp"

namespace kami
{
	class c_time
	{
	private:
		static t_uint	last_frame;
		static t_uint	ellapsed_time;
		static t_uint	fps;
		static t_uint	frame_duration;

	public:
		static void		restart(void);
		static void		update(void);
		static void		manage_lock(void);

		static t_uint	delta_time(void);
		static t_uint	time(void);
		
	};
}
