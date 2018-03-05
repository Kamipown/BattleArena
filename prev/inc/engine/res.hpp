#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector>

#include "defs.hpp"
#include "window.hpp"
#include "error.hpp"

namespace	kami
{
	struct	s_image
	{
		SDL_Texture	*texture;
		t_point		size;
	};

	class	c_res : public c_window
	{
	protected:
		static std::vector<s_image>	images;

	public:
		static void		unload(void);
		static t_uint	load_image(const char *filename);
		static int		get_image_width(const t_uint id);
		static int		get_image_height(const t_uint id);

		// SDL_Texture		*get_texture(void){return (this->texture);}
		// t_point			get_size(void) const {return (this->size);}
		// int				get_width(void) const {return (this->size.x);}
		// int				get_height(void) const {return (this->size.y);}
	};
}
