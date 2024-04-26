#include "Engine.h"

#include "Window.h"
#include "Vulkan/VK_Instance.h"
#include "Vulkan/VK_PhysicalDevice.h"

#include "Utility/Debug.h"

Engine::Engine() : 
	m_window(nullptr),
	m_instance(nullptr),
	m_physicalDevice(nullptr)
{
}

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

	m_instance = new VK_Instance();
	m_physicalDevice = new VK_PhysicalDevice(m_instance->Get());
	
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