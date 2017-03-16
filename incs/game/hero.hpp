#pragma once

#include <iostream>
// #include "defs.hpp"
#include "event.hpp"
#include "time.hpp"
#include "gfx.hpp"
#include "res.hpp"
#include "animator.hpp"

using namespace kami;

class c_hero
{
protected:
	c_animator	animator;
	s_vec2f		position;
	t_uint		move_speed;
	t_uint		state;
	bool		face_left;

public:
	c_hero(void);
	~c_hero(void);

	void	draw(void) const;
	void	update(void);
	t_rect	get_subrect(void) const;
	s_vec2f	get_position(void) const;
	float	get_position_x(void) const;
	float	get_position_y(void) const;
	void	set_position(const s_vec2f &pos);
	void	set_position_x(const float x);
	void	set_position_y(const float y);
	void	move(const s_vec2f mv);

};
