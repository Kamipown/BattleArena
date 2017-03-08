#include "arena.hpp"

c_arena::c_arena(void)
{

}

c_arena::~c_arena(void)
{

}

void	c_arena::print_map(void)
{
	std::cout << "Arena tilesheet: " << this->tilesheet_filename << std::endl;
	for (t_uint8 y = 0; y < 27; ++y)
	{
		for (t_uint8 x = 0; x < 48; ++x)
		{
			std::cout << this->cells[x][y] << " ";
		}
		std::cout << std::endl;
	}
}

void	c_arena::load_map(const std::string filename)
{
	std::ifstream	file(filename.c_str(), std::ios::in);
	t_uint			cell_value;

	if (!file)
	{
		std::cout << "Open fail\n";
		return ;
	}
	file >> this->tilesheet_filename;
	this->tilesheet.load(this->tilesheet_filename.c_str());
	for (t_uint8 y = 0; y < 27; ++y)
	{
		for (t_uint8 x = 0; x < 48; ++x)
		{
			if (!(file >> cell_value))
				this->cells[x][y] = 0;
			else
				this->cells[x][y] = cell_value;
		}
	}
	file.close();
}

void	c_arena::init(const std::string filename)
{
	this->load_map(filename);
	this->print_map();
}

void	c_arena::draw(void)
{
	t_rect	r;
	t_point	p;
	t_uint	tw;

	tw = this->tilesheet.get_width() / 40;
	for (t_uint8 y = 0; y < 27; ++y)
	{
		for (t_uint8 x = 0; x < 48; ++x)
		{
			if (this->cells[x][y])
			{
				r.x = ((this->cells[x][y] - 1) % tw) * 40;
				r.y = ((this->cells[x][y] - 1) / tw) * 40;
				r.w = 40;
				r.h = 40;
				p = (t_point){x * 40, y * 40};
				c_gfx::draw_image(this->tilesheet, r, p);
			}
		}
	}
}
