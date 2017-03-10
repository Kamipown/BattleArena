#pragma once

#include "engine.hpp"
#include "window.hpp"
#include "gfx.hpp"
#include "event.hpp"
#include "time.hpp"
#include "timer.hpp"
#include "scene.hpp"
#include "scene_sandbox.hpp"
#include "scene_splashscreen.hpp"
#include "scene_arena_2.hpp"
#include "scene_arena_3.hpp"

using namespace kami;

class	c_game
{
private:
	c_scene	*scene;

	void	start(void);
	void	change_scene(t_uint8 scene_id);

public:
	c_game(void);
	~c_game(void);
	
};
