#pragma once

#include "gfx.hpp"
#include "image.hpp"

#include "scene.hpp"
#include "arena.hpp"

using namespace kami;

class c_scene_arena_1 : public c_scene
{
private:
	c_arena	arena;
	c_image pixelart;

public:
	c_scene_arena_1(void);
	~c_scene_arena_1(void);

	virtual t_uint8	process(void);

};
