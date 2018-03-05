#pragma once

#include "defs.hpp"

class	c_scene
{
private:


public:
	c_scene(void);
	virtual ~c_scene(void);

	virtual t_uint8	process(void) = 0;
	
};
