#include "Window.h"

#include <iostream>
#include "Utility/Debug.h"


Window::Window(int w, int h, const char* n) : 
	m_width(w), 
	m_height(h), 
	m_name(n)
{
	create_window();
}

Window::~Window()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void Window::PollEvents()
{
	while (!glfwWindowShouldClose(m_window)) 
	{
		glfwPollEvents();
	}
}

void Window::create_window()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Ask GLFW not to use OpenGL by default
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Temporarily disable the window resize

	m_window = glfwCreateWindow(m_width, m_height, m_name, nullptr, nullptr);
	if (m_window == NULL)
	{
		Debug::Exception("Failed to create GLFW window");
		glfwTerminate();
		return;
	}
}