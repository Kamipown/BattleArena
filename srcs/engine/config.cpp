#include "config.hpp"

namespace kami
{
	bool c_config::fullscreen = true;

	void		c_config::init(void)
	{
		std::ifstream						conf_stream("config.cfg");
		std::string							line;
		std::istringstream					iss;
		std::pair<std::string, std::string>	values;

		if (conf_stream)
		{
			while (std::getline(conf_stream, line))
			{
				iss.str(line);
				iss >> values.first >> values.second;
				std::cout << values.first << " " << values.second << std::endl;
				if (values.first == "fullscreen")
					c_config::fullscreen = (bool)std::atoi(values.second.c_str());
				iss.clear();
			}
			conf_stream.close();
		}
	}

	void		c_config::save(void)
	{
		
	}
}
