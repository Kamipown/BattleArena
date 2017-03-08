#include "window.hpp"

namespace kami
{
	SDL_Window		*c_window::window = 0;
	SDL_Renderer	*c_window::renderer = 0;
	bool			c_window::opened = false;

	void	c_window::open(void)
	{
		if (!(c_window::window = SDL_CreateWindow("Kami", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 320, 240, SDL_WINDOW_RESIZABLE)))
			c_error::set(5, "Can't create window.");
		if (!(c_window::renderer = SDL_CreateRenderer(c_window::window, -1, SDL_RENDERER_ACCELERATED)))
		{
			SDL_DestroyWindow(c_window::window);
			c_error::set(6, "Can't create renderer.");
		}
		c_window::opened = true;
	}

	void	c_window::close(void)
	{
		SDL_DestroyRenderer(c_window::renderer);
		SDL_DestroyWindow(c_window::window);
		c_window::opened = false;
	}

	bool	c_window::is_open(void)
	{
		return (c_window::opened);
	}

	t_point	c_window::get_size(void)
	{
		t_point size;

		SDL_GetWindowSize(c_window::window, &size.x, &size.y);
		return (size);
	}

	void	c_window::set_size(t_point size)
	{
		SDL_SetWindowSize(c_window::window, size.x, size.y);
	}
}
