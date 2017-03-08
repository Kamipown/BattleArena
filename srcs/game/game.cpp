#include "game.hpp"

c_game::c_game(void)
{
	c_engine::init();
	
	this->scene = new c_scene_arena_1();
	this->start();
}

c_game::~c_game(void)
{
	delete (this->scene);
	c_engine::quit();
}

void	c_game::change_scene(t_uint8 scene_id)
{
	delete (this->scene);
	if (scene_id == 1)
		this->scene = new c_scene_arena_1();
	else if (scene_id == 2)
		this->scene = new c_scene_arena_2();
	else if (scene_id == 3)
		this->scene = new c_scene_arena_3();
	std::cout << "Change scene to scene_arena_" << (int)scene_id << std::endl;
}

void	c_game::start(void)
{
	c_time::restart();
	while (c_window::is_open())
	{
		c_event::update();
		if (c_event::keyboard_1)
			this->change_scene(1);
		if (c_event::keyboard_2)
			this->change_scene(2);
		if (c_event::keyboard_3)
			this->change_scene(3);
		c_gfx::clear();
		this->scene->process();
		// c_gfx::lighting();
		c_gfx::render();
		c_time::update();
		if (c_event::quit || c_event::escape)
			c_window::close();
	}
}
