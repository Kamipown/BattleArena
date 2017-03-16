#include "game.hpp"

c_game::c_game(void)
{
	c_engine::init();
	
	this->scene = new c_scene_sandbox();
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
		this->scene = new c_scene_splashscreen();
	else if (scene_id == 2)
		this->scene = new c_scene_arena_2();
	else if (scene_id == 3)
		this->scene = new c_scene_sandbox();
	std::cout << "Change scene to scene_arena_" << (int)scene_id << std::endl;
}

void	c_game::start(void)
{
	c_timer	fps_timer;
	t_uint	frames = 0;

	while (c_window::is_open())
	{
		c_event::update();
		if (c_event::keyboard_1)
			c_time::manage_lock();
		if (c_event::keyboard_2)
			this->change_scene(2);
		if (c_event::keyboard_3)
			this->change_scene(3);

		c_gfx::clear();
		this->scene->process();
		if (fps_timer.is_ellapsed_s(1))
		{
			std::cout << frames << std::endl;
			fps_timer.reset();
			frames = 0;
		}
		frames++;
		c_gfx::render();
		c_time::update();
		if (c_event::quit || c_event::escape)
			c_window::close();
	}
}
