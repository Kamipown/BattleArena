#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "defs.hpp"
#include "gfx.hpp"
#include "image.hpp"

using namespace kami;

class	c_arena
{
private:
	std::string	tilesheet_filename;
	c_image		tilesheet;
	t_uint		cells[48][27];

	void		load_map(const std::string filename);
	void		print_map(void);

public:
	c_arena(void);
	~c_arena(void);

	void		init(const std::string filename);
	void		draw(void);
	
};
