#include "animator.hpp"

namespace kami
{
	c_animator::c_animator(void)
	{
		this->anim_start = c_time::time();
		this->current = 0;
	}

	t_uint	c_animator::add_animation(t_uint texture_id, t_uint frame_count, t_uint frame_duration)
	{
		this->animations.push_back((s_animation){texture_id, frame_count, frame_duration});
		return (this->animations.size() - 1);
	}

	t_rect	c_animator::get_subrect(void) const
	{
		int n =	(c_time::time() - this->anim_start)
				/ this->animations[this->current].frame_duration
				% this->animations[this->current].frame_count
				* (int)(c_res::get_image_width(this->current)
					/ this->animations[this->current].frame_count);

		// std::cout << n << std::endl;
		return ((t_rect)
		{
			(int)n,
			0,
			(int)(c_res::get_image_width(this->current) / this->animations[this->current].frame_count),
			c_res::get_image_width(this->current)
		});
	}

	t_uint	c_animator::get_current(void) const
	{
		return (this->current);
	}

	void	c_animator::set_current(const t_uint n)
	{
		if (this->current == n)
			return ;
		this->current = n;
		this->anim_start = c_time::time();
	}
}
