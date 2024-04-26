#pragma once

#include <GLFW/glfw3.h>

#include <memory>


class Window
{
public:
	Window(int w, int h, const char* n); 
	~Window();

	void PollEvents();

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

private: 
	void create_window();

	const int m_width;
	const int m_height;
	const char*  m_name; 
	GLFWwindow* m_window;
};