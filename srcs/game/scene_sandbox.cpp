#include "scene_sandbox.hpp"

c_scene_sandbox::c_scene_sandbox(void) : c_scene()
{
	c_res::load_image("img/mage_idle.png");
	//this->arena.init("maps/sandbox");
	// this->pixelart.load("img/pixelart.png");
	// this->mage_idle.load("img/mage_idle.png");
	this->kamipown = new c_hero_mage();
	this->kamipown->set_position((t_point){70, 20});

}

c_scene_sandbox::~c_scene_sandbox(void)
{
	c_res::unload();
}

t_uint8	c_scene_sandbox::process(void)
{
	// t_rect	sub = (t_rect){36, 0, 18, 23};
	// t_rect	dst = (t_rect){50, 20, 18, 23};
	// c_gfx::draw_image(0);
	// c_gfx::draw_image(0, &sub, &dst);
	this->kamipown->draw();
	//this->arena.draw();
	// c_gfx::draw_image(this->pixelart);
	// c_gfx::draw_image(this->mage_idle, (t_point){124, 108});
	// this->kamipown.draw();
	return (0);
}
