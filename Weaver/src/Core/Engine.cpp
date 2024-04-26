#include "Engine.h"

#include "Window.h"
#include "VulkanInstance.h"

#include "Utility/Debug.h"

void Engine::initialize_engine()
{
	// Create the GLFW Window
	if (m_window = new Window(WIDTH, HEIGHT, "Weaver"))
	{
		Debug::Log(Log, "Engine::ctor()::Created GLFW Window");
	}
	else
	{
		Debug::Exception("Engine::ctor()::Failed to create window");
	}

	// Create a Vulkan Instance
	if (m_vulkanInstance = new VulkanInstance())
	{
		Debug::Log(Log, "Engine::ctor()::Created Vulkan instance");
	}
	else
	{
		Debug::Exception("Engine::ctor()::Failed to create Vulkan instance");
	}
}

void Engine::Run()
{
	initialize_engine();
	main_loop();
}

void Engine::main_loop()
{
	if (m_window)
	{
		m_window->PollEvents();
	}
}