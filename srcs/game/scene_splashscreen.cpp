#include "scene_splashscreen.hpp"

c_scene_splashscreen::c_scene_splashscreen(void) : c_scene()
{
	//this->arena.init("maps/splashscreen");
	this->pixelart.load("img/pixelart.png");
}

c_scene_splashscreen::~c_scene_splashscreen(void)
{
	
}

t_uint8	c_scene_splashscreen::process(void)
{
	//this->arena.draw();
	c_gfx::draw_image(this->pixelart);
	return (0);
}
