#pragma once

#include <iostream>
#include "gfx.hpp"
#include "res.hpp"
#include "animator.hpp"

using namespace kami;

class c_hero
{
protected:
	c_animator	animator;
	t_point		position;

public:
	c_hero(void);
	~c_hero(void);

	void	draw(void) const;
	t_rect	get_subrect(void) const;
	t_point	get_position(void) const;
	int		get_position_x(void) const;
	int		get_position_y(void) const;
	void	set_position(const t_point &pos);
	void	set_position_x(const int x);
	void	set_position_y(const int y);

};
