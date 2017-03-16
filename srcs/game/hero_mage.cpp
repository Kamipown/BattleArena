#include "hero_mage.hpp"

c_hero_mage::c_hero_mage(void)
{
	this->move_speed = 60;
	this->animator.add_animation(0, 4, 250);
	this->animator.add_animation(1, 4, 250);
}

c_hero_mage::~c_hero_mage(void)
{
	
}
