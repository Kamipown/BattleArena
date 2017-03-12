#include "hero.hpp"

c_hero::c_hero(void)
{

}

c_hero::~c_hero(void)
{
	
}

void	c_hero::draw(void) const
{
	SDL_Rect	sub = this->animator.get_subrect();
	SDL_Rect	dst = (SDL_Rect)
	{
		this->position.x,
		this->position.y,
		c_res::get_image_width(0) / 4,
		c_res::get_image_height(0)
	};
	
	c_gfx::draw_image(0, &sub, &dst);
}

t_rect	c_hero::get_subrect(void) const
{
	return (this->animator.get_subrect());
}

t_point	c_hero::get_position(void) const
{
	return (this->position);
}

int		c_hero::get_position_x(void) const
{
	return (this->position.x);
}

int		c_hero::get_position_y(void) const
{
	return (this->position.y);
}

void	c_hero::set_position(const t_point &pos)
{
	this->position = pos;
}

void	c_hero::set_position_x(const int x)
{
	this->position.x = x;
}

void	c_hero::set_position_y(const int y)
{
	this->position.y = y;
}
