#include "res.hpp"

namespace kami
{
	std::vector<s_image>	c_res::images;

	void	c_res::unload(void)
	{
		for (t_uint i = 0; i < c_res::images.size(); ++i)
			SDL_DestroyTexture(c_res::images[i].texture);
		c_res::images.clear();
	}

	t_uint	c_res::load_image(const char *filename)
	{
		s_image	img;

		if (!(img.texture = IMG_LoadTexture(c_window::renderer, filename)))
			c_error::set(1, "Can't load image.");
		SDL_QueryTexture(img.texture, 0, 0, &img.size.x, &img.size.y);
		c_res::images.push_back(img);
		return (c_res::images.size() - 1);
	}

	int		c_res::get_image_width(const t_uint id)
	{
		return (c_res::images[id].size.x);
	}

	int		c_res::get_image_height(const t_uint id)
	{
		return (c_res::images[id].size.y);
	}
}
