#include "scene_arena_1.hpp"

c_scene_arena_1::c_scene_arena_1(void) : c_scene()
{
	//this->arena.init("maps/arena_1");
	this->pixelart.load("img/pixelart.png");
}

c_scene_arena_1::~c_scene_arena_1(void)
{
	
}

t_uint8	c_scene_arena_1::process(void)
{
	//this->arena.draw();
	c_gfx::draw_image(this->pixelart);
	return (0);
}
