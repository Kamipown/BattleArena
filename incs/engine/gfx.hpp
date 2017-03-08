#pragma once

#include <SDL2/SDL.h>

#include "defs.hpp"
#include "window.hpp"
#include "image.hpp"

namespace	kami
{
	// class image;

	class	c_gfx : public c_window
	{
	private:
		static t_color	draw_color;

	public:
		static void		set_draw_color(const t_color color);

		static void		clear(void);
		static void		lighting(void);
		static void		render(void);

		static void		draw_pixel(const t_point pos);
		static void		draw_line(const t_point from, const t_point to);
		static void		draw_rect(const t_rect rect);
		static void		fill_rect(const t_rect rect);
		static void		draw_image(c_image &img);
		static void		draw_image(c_image &img, const t_point pos);
		static void		draw_image(c_image &img, const t_rect sub, const t_point p);
		// static void		draw_image(image &img, t_rect subrect, const t_point pos);
		// static void		draw_tile(tilesheet &t, const t_uint tile_id, const t_point pos);
		
	};
}
