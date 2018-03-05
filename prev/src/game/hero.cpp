#include "hero.hpp"

c_hero::c_hero(void)
{
	this->state = 0;
	this->face_left = false;
}

c_hero::~c_hero(void)
{
	
}

void	c_hero::update(void)
{
	s_vec2f	mv = (s_vec2f){0, 0};
	float	dist = (float)(this->move_speed * c_time::delta_time()) / 1000;

	if (c_event::arrows[top] && c_event::arrows[right])
		mv = (s_vec2f){dist * 0.7f, -dist * 0.7f};
	else if (c_event::arrows[top] && c_event::arrows[left])
		mv = (s_vec2f){-dist * 0.7f, -dist * 0.7f};
	else if (c_event::arrows[down] && c_event::arrows[right])
		mv = (s_vec2f){dist * 0.7f, dist * 0.7f};
	else if (c_event::arrows[down] && c_event::arrows[left])
		mv = (s_vec2f){-dist * 0.7f, dist * 0.7f};
	else if (c_event::arrows[top])
			mv.y -= dist;
	else if (c_event::arrows[right])
			mv.x += dist;
	else if (c_event::arrows[down])
			mv.y += dist;
	else if (c_event::arrows[left])
			mv.x -= dist;

	if (mv.x != 0 || mv.y != 0)
	{

		this->move(mv);
		this->animator.set_current(1);
		if (mv.x < 0)
			this->face_left = true;
		else if (mv.x > 0)
			this->face_left = false;

		if (this->position.x > 320)
			this->position.x -= 320;
		else if (this->position.x < 0)
			this->position.x += 320;

		if (this->position.y > 240)
			this->position.y -= 240;
		else if (this->position.y < 0)
			this->position.y += 240;
	}
	else
		this->animator.set_current(0);
	// std::cout << this->position.x << " " << this->position.y << std::endl;
}

void	c_hero::draw(void) const
{
	SDL_Rect	sub = this->animator.get_subrect();
	SDL_Rect	dst = (SDL_Rect)
	{
		(int)round(this->position.x),
		(int)round(this->position.y),
		c_res::get_image_width(0) / 4,
		c_res::get_image_height(0)
	};
	c_gfx::draw_image(this->animator.get_current(), &sub, &dst, this->face_left);
}

t_rect	c_hero::get_subrect(void) const
{
	return (this->animator.get_subrect());
}

s_vec2f	c_hero::get_position(void) const
{
	return (this->position);
}

float		c_hero::get_position_x(void) const
{
	return (this->position.x);
}

float		c_hero::get_position_y(void) const
{
	return (this->position.y);
}

void	c_hero::set_position(const s_vec2f &pos)
{
	this->position = pos;
}

void	c_hero::set_position_x(const float x)
{
	this->position.x = x;
}

void	c_hero::set_position_y(const float y)
{
	this->position.y = y;
}

void	c_hero::move(const s_vec2f mv)
{
	this->position.x += mv.x;
	this->position.y += mv.y;
}
