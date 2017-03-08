#pragma once

#include "scene.hpp"
#include "arena.hpp"

class c_scene_arena_1 : public c_scene
{
private:
	c_arena	arena;

public:
	c_scene_arena_1(void);
	~c_scene_arena_1(void);

	virtual t_uint8	process(void);

};
