#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

namespace	kami
{
	class	c_error
	{
	private:
		static void	log(const int code, const std::string message);
		static void	abort(const int code);

	public:
		static void	set(const int code, const std::string message);

	};
}
