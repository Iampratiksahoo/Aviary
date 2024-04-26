#pragma once

#include <iostream>
#include <cstdlib>
#include <memory>


class Window;
class VK_Instance;
class VK_PhysicalDevice;
class Engine
{
public:
    Engine();
    void Run();

    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

private:
    void initialize_engine();
    void main_loop();

    Window* m_window;
    VK_Instance* m_instance;
    VK_PhysicalDevice* m_physicalDevice;
};


