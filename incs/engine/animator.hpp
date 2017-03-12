#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#include "defs.hpp"
#include "res.hpp"
#include "time.hpp"

using namespace kami;

struct		s_animation
{
	t_uint	texture_id;
	t_uint	frame_count;
	t_uint	frame_duration;
};

namespace	kami
{
	class	c_animator
	{
	private:
		std::vector<s_animation>	animations;
		t_uint						anim_start;
		t_uint						current;

	public:
		c_animator(void);
		t_uint	add_animation(t_uint texture_id, t_uint frame_count, t_uint frame_duration);
		t_rect	get_subrect(void) const;
		
	};
}
