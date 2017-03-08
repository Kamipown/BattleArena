#pragma once

#include "engine.hpp"
#include "window.hpp"
#include "gfx.hpp"
#include "event.hpp"
#include "time.hpp"
#include "scene.hpp"
#include "scene_arena_1.hpp"
#include "scene_arena_2.hpp"
#include "scene_arena_3.hpp"

using namespace kami;

class	c_game
{
private:
	c_scene	*scene;

	void	start(void);
	void	change_scene(t_uint8 scene_id);
	void	loop(void);

public:
	c_game(void);
	~c_game(void);
	
};
