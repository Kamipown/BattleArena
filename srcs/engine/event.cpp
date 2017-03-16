#include "event.hpp"

namespace kami
{
	SDL_Event		c_event::event;
	bool			c_event::arrows[4] = {false, false, false, false};
	bool			c_event::quit = false;
	bool			c_event::escape = false;
	bool			c_event::keyboard_1 = false;
	bool			c_event::keyboard_2 = false;
	bool			c_event::keyboard_3 = false;
	bool			c_event::mouse_left = false;
	t_point			c_event::mouse_click = (t_point){0, 0};

	void	c_event::reset(void)
	{
		c_event::keyboard_1 = false;
		c_event::keyboard_2 = false;
		c_event::keyboard_3 = false;
	}

	void	c_event::update(void)
	{
		c_event::reset();
		while (SDL_PollEvent(&c_event::event))
		{
			if (c_event::event.type == SDL_QUIT)
				c_event::quit = true;
			else if (c_event::update_keyboard()
			 	|| c_event::update_mouse()
			 	|| c_event::update_window())
				continue ;
		}
		SDL_GetMouseState(&c_event::mouse_click.x, &c_event::mouse_click.y);
	}

	bool	c_event::update_keyboard(void)
	{
		if (c_event::event.type == SDL_KEYDOWN)
		{
			if (c_event::event.key.keysym.sym == SDLK_ESCAPE)
				c_event::escape = true;
			else if (c_event::event.key.keysym.sym == SDLK_UP)
				c_event::arrows[top] = true;
			else if (c_event::event.key.keysym.sym == SDLK_RIGHT)
				c_event::arrows[right] = true;
			else if (c_event::event.key.keysym.sym == SDLK_DOWN)
				c_event::arrows[down] = true;
			else if (c_event::event.key.keysym.sym == SDLK_LEFT)
				c_event::arrows[left] = true;
			else if (c_event::event.key.keysym.sym == SDLK_a)
				c_event::keyboard_1 = true;
			else if (c_event::event.key.keysym.sym == SDLK_z)
				c_event::keyboard_2 = true;
			else if (c_event::event.key.keysym.sym == SDLK_e)
				c_event::keyboard_3 = true;
			return (true);
		}
		else if (c_event::event.type == SDL_KEYUP)
		{
			if (c_event::event.key.keysym.sym == SDLK_UP)
				c_event::arrows[top] = false;
			else if (c_event::event.key.keysym.sym == SDLK_RIGHT)
				c_event::arrows[right] = false;
			else if (c_event::event.key.keysym.sym == SDLK_DOWN)
				c_event::arrows[down] = false;
			else if (c_event::event.key.keysym.sym == SDLK_LEFT)
				c_event::arrows[left] = false;
			return (true);
		}
		return (false);
	}

	bool	c_event::update_mouse(void)
	{
		if (c_event::event.type == SDL_MOUSEBUTTONUP)
		{
			if (c_event::event.button.button == 1)
				c_event::mouse_left = false;
			return (true);
		}
		else if (c_event::event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (c_event::event.button.button == 1)
				c_event::mouse_left = true;
			return (true);
		}
		return (false);
	}

	bool	c_event::update_window(void)
	{
		if (c_event::event.type == SDL_WINDOWEVENT)
		{
			if (c_event::event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
				c_gfx::update_layer_dst();
			return (true);
		}
		return (false);
	}
}
