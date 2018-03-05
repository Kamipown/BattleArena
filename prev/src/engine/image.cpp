#include "image.hpp"

namespace kami
{
	c_image::c_image(void)
	{
		this->texture = 0;
		this->size.x = 0;
		this->size.y = 0;
	}

	c_image::c_image(const char *filename)
	{
		this->load(filename);
	}

	c_image::~c_image(void)
	{
		if (this->texture)
			SDL_DestroyTexture(this->texture);
	}

	void	c_image::load(const char *filename)
	{
		if (!(this->texture = IMG_LoadTexture(c_window::renderer, filename)))
		{
			c_error::set(1, "Can't load image.");
			return ;
		}
		SDL_QueryTexture(this->texture, 0, 0, &this->size.x, &this->size.y);
	}
}
