#include "gfx.hpp"
#include <iostream>

namespace kami
{
	SDL_Texture	*c_gfx::layer = 0;
	t_rect		c_gfx::layer_dst;
	t_color		c_gfx::draw_color = (t_color){255, 255, 255, 255};

	void	c_gfx::init(void)
	{
		if (!(c_gfx::layer = SDL_CreateTexture(c_window::renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 320, 240)))
		{
			std::cout << SDL_GetError() << std::endl;
			c_error::set(7, "Can't create layer.");
		}
		SDL_SetTextureBlendMode(c_gfx::layer, SDL_BLENDMODE_BLEND);
		c_gfx::update_layer_dst();
	}

	void	c_gfx::update_layer_dst(void)
	{
		t_point	size = c_window::get_size();

		if (size.x / (double)size.y > 1.334)
		{
			c_gfx::layer_dst.h = size.y;
			c_gfx::layer_dst.w = c_gfx::layer_dst.h * 1.333;
			c_gfx::layer_dst.x = (size.x - c_gfx::layer_dst.w) / 2;
			c_gfx::layer_dst.y = 0;
		}
		else
		{
			c_gfx::layer_dst.w = size.x;
			c_gfx::layer_dst.h = c_gfx::layer_dst.w * 0.75;
			c_gfx::layer_dst.x = 0;
			c_gfx::layer_dst.y = (size.y - c_gfx::layer_dst.h) / 2;
		}
	}

	void	c_gfx::set_draw_color(const t_color c)
	{
		c_gfx::draw_color = (t_color){c.r, c.g, c.b, c.a};
	}

	void	c_gfx::clear(void)
	{
		SDL_SetRenderDrawColor(c_window::renderer, 0, 0, 0, 255);
		SDL_RenderClear(c_window::renderer);
		SDL_SetRenderTarget(c_window::renderer, c_gfx::layer);		
		SDL_RenderClear(c_window::renderer);
		SDL_SetRenderDrawColor(c_window::renderer, c_gfx::draw_color.r, c_gfx::draw_color.g, c_gfx::draw_color.b, c_gfx::draw_color.a);
	}

	void	c_gfx::lighting(void)
	{
		t_rect		r;
		SDL_Texture	*t;

		r = (t_rect){0, 0, 1920, 1080};
		t = SDL_CreateTexture(c_window::renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1920, 1080);
		SDL_SetRenderTarget(c_window::renderer, t);
		SDL_SetRenderDrawColor(c_window::renderer, 10, 10, 10, 128);
		SDL_RenderFillRect(c_window::renderer, &r);
		SDL_SetRenderDrawColor(c_window::renderer, c_gfx::draw_color.r, c_gfx::draw_color.g, c_gfx::draw_color.b, c_gfx::draw_color.a);
		SDL_SetRenderTarget(c_window::renderer, 0);
		SDL_RenderCopy(c_window::renderer, t, 0, 0);
	}

	void	c_gfx::render(void)
	{
		SDL_SetRenderTarget(c_window::renderer, 0);
		SDL_RenderCopy(c_window::renderer, c_gfx::layer, 0, &c_gfx::layer_dst);
		SDL_RenderPresent(c_window::renderer);
	}


	void	c_gfx::draw(c_image &img, const t_rect *sub, const t_rect *dst)
	{
		std::cout << sub->x << ' ' << sub->y << ' ' << sub->w << ' ' << sub->h << std::endl;
		std::cout << dst->x << ' ' << dst->y << ' ' << dst->w << ' ' << dst->h << std::endl;
		SDL_RenderCopy(c_window::renderer, img.get_texture(), sub, dst);
	}

	void	c_gfx::draw_pixel(const t_point p)
	{
		SDL_RenderDrawPoint(c_window::renderer, p.x, p.y);
	}

	void	c_gfx::draw_line(const t_point from, const t_point to)
	{
		SDL_RenderDrawLine(c_window::renderer, from.x, from.y, to.x, to.y);
	}

	void	c_gfx::draw_rect(const t_rect rect)
	{
		SDL_RenderDrawRect(c_window::renderer, &rect);
	}

	void	c_gfx::fill_rect(const t_rect rect)
	{
		SDL_RenderFillRect(c_window::renderer, &rect);
	}

	void	c_gfx::draw_image(const t_uint id)
	{
		SDL_RenderCopy(c_window::renderer, c_res::images[id].texture, 0, 0);
	}

	void	c_gfx::draw_image(const t_uint id, const t_rect *sub, const t_rect *dst, const bool flip)
	{
		t_rect	tdst = *dst;

		if (flip)
		{
			SDL_RenderCopyEx(c_window::renderer, c_res::images[id].texture, sub, dst, 0, 0, SDL_FLIP_HORIZONTAL);
			if (dst->x + sub->w >= 320)
			{
				tdst.x -= 320;
				SDL_RenderCopyEx(c_window::renderer, c_res::images[id].texture, sub, &tdst, 0, 0, SDL_FLIP_HORIZONTAL);
			}
		}
		else
		{
			SDL_RenderCopy(c_window::renderer, c_res::images[id].texture, sub, dst);
			if (dst->x + sub->w >= 320)
			{
				tdst.x -= 320;
				SDL_RenderCopy(c_window::renderer, c_res::images[id].texture, sub, &tdst);
			}
		}
	}

	void	c_gfx::draw_image(c_image &image)
	{
		SDL_RenderCopy(c_window::renderer, image.get_texture(), 0, 0);
	}

	void	c_gfx::draw_image(c_image &image, const t_point p)
	{
		SDL_Rect	dst;

		dst.x = p.x;
		dst.y = p.y;
		dst.w = image.get_width();
		dst.h = image.get_height();
		SDL_RenderCopy(c_window::renderer, image.get_texture(), 0, &dst);
	}

	void	c_gfx::draw_image(c_image &image, const t_rect sub, const t_point p)
	{
		SDL_Rect	dst;

		dst.x = p.x;
		dst.y = p.y;
		dst.w = 40;
		dst.h = 40;
		SDL_RenderCopy(c_window::renderer, image.get_texture(), &sub, &dst);
	}

	// void	c_gfx::draw_tile(spritesheet &s, t_uint id, const t_point p)
	// {
	// 	SDL_Rect	src;
	// 	SDL_Rect	dst;

	// 	src.x = 

	// 	dst.x = p.x;
	// 	dst.y = p.y;
	// 	dst.w = t.get_tile_width();
	// 	dst.h = t.get_tile_height();
	// 	SDL_RenderCopy(c_window::renderer, t.get_texture(), 0, &dst);
	// }
}
