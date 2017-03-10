#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include "defs.hpp"

namespace kami
{
	class c_timer
	{
	private:
		t_uint	start_time;

	public:
		c_timer(void);

		void	reset(void);
		t_uint	get_ms(void);
		t_uint	get_s(void);
		t_uint	get_min(void);
		bool	is_ellapsed_ms(const t_uint ms) const;
		bool	is_ellapsed_s(const t_uint s) const;
		bool	is_ellapsed_min(const t_uint min) const;
		
	};
}
