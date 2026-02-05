#include "../includes/Server.hpp"
#include <iostream>
#include <cstdlib>
static bool ft_check(int ac, char **av)
{
	if (ac != 3)
	{
		std::cerr << "Usage: " << av[0] << " <port> <password>" << std::endl;
		return false;
	}
	for(int i = 0; av[1][i]; i++)
	{
		if(!std::isdigit(av[1][i]))
		{
			std::cerr << "Error: only numbers can be used for the <port> argument" << std::endl;
			return false;
		}
	}
	return true;	
}

int main(int ac, char **av)
{
	if (!ft_check(ac, av))
		return 1;
	int port = std::atoi(av[1]);
	std::string password = av[2];
	if (!password.empty())
	{
		try
		{
			Server server(port, password);
			server.run();
			return 0;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return 1;
		}
	}
	std::cerr << "Error: the server password cannot be empty." << std::endl;
	return 1;
}