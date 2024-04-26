#include "Core/Engine.h"


int main(void)
{
	Engine Engine;
	try
	{
		Engine.Run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}