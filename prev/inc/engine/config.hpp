#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <utility>
#include <cstdlib>

namespace kami
{
	class 		c_config
	{
	private:
		static bool		fullscreen;

	protected:
		static void		init(void);
		static void		save(void);

	public:
		static bool		get_fullscreen(void) {return (c_config::fullscreen);}
		
	};
}
