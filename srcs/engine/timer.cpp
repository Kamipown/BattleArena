#include "timer.hpp"

namespace kami
{
	c_timer::c_timer(void)
	{
		this->reset();
	}

	void	c_timer::reset(void)
	{
		this->start_time = SDL_GetTicks();
	}

	t_uint	c_timer::get_ms(void)
	{
		return (SDL_GetTicks() - this->start_time);
	}

	t_uint	c_timer::get_s(void)
	{
		return ((SDL_GetTicks() - this->start_time) / 1000);
	}

	t_uint	c_timer::get_min(void)
	{
		return ((SDL_GetTicks() - this->start_time) / 60000);
	}

	bool	c_timer::is_ellapsed_ms(const t_uint ms) const
	{
		return (ms <= (SDL_GetTicks() - this->start_time));
	}

	bool	c_timer::is_ellapsed_s(const t_uint s) const
	{
		return (s <= (SDL_GetTicks() - this->start_time) / 1000);
	}

	bool	c_timer::is_ellapsed_min(const t_uint min) const
	{
		return (min <= (SDL_GetTicks() - this->start_time) / 60000);
	}

}
