#include "scene_sandbox.hpp"

c_scene_sandbox::c_scene_sandbox(void) : c_scene()
{
	//this->arena.init("maps/sandbox");
	this->pixelart.load("img/pixelart.png");
	this->mage.load("img/mage_idle.png");
}

c_scene_sandbox::~c_scene_sandbox(void)
{
	
}

t_uint8	c_scene_sandbox::process(void)
{
	//this->arena.draw();
	// c_gfx::draw_image(this->pixelart);
	c_gfx::draw_image(this->mage, (t_point){124, 108});
	return (0);
}
