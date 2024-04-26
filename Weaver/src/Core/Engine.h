#pragma once

#include <iostream>
#include <cstdlib>
#include <memory>


class Window;
class VulkanInstance; 
class Engine
{
public:
    void Run();

    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

private:
    void initialize_engine();
    void main_loop();

    Window* m_window;
    VulkanInstance* m_vulkanInstance;
};


