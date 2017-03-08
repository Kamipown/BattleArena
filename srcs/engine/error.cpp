#include "error.hpp"

namespace kami
{
	void			c_error::log(const int code, const std::string message)
	{
		std::cerr << "(" << code <<  ") Error: " << message << std::endl;
	}

	void			c_error::abort(const int code)
	{
		exit(code);
	}

	void			c_error::set(const int code, const std::string message)
	{
		c_error::log(code, message);
		c_error::abort(code);
	}
}
