#pragma once

#include "gfx.hpp"
#include "res.hpp"
#include "image.hpp"
#include "time.hpp"

#include "scene.hpp"
#include "arena.hpp"
#include "hero.hpp"
#include "hero_mage.hpp"

using namespace kami;

class c_scene_sandbox : public c_scene
{
private:
	// c_arena	arena;
	// c_image pixelart;
	// c_image mage_idle;

	c_hero	*kamipown;

public:
	c_scene_sandbox(void);
	~c_scene_sandbox(void);

	virtual t_uint8	process(void);

};
