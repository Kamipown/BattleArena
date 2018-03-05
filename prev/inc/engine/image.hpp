#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "window.hpp"
#include "error.hpp"

namespace	kami
{
	class	c_image : public c_window
	{
	private:
		SDL_Texture	*texture;
		t_point		size;

	public:
		c_image(void);
		c_image(const char *filename);
		~c_image(void);

		void			load(const char *filename);

		SDL_Texture		*get_texture(void){return (this->texture);}
		t_point			get_size(void) const {return (this->size);}
		int				get_width(void) const {return (this->size.x);}
		int				get_height(void) const {return (this->size.y);}
	};
}
