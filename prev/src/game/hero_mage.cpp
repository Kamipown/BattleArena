#include "hero_mage.hpp"

c_hero_mage::c_hero_mage(void)
{
	this->move_speed = 70;
	this->animator.add_animation(0, 4, 250);
	this->animator.add_animation(1, 4, 125);
}

c_hero_mage::~c_hero_mage(void)
{
	
}
