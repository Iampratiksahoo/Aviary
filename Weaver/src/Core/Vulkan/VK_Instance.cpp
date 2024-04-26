#include "VK_Instance.h"

#include "GLFW/glfw3.h"
#include "Utility/Debug.h"
#include "vector"

VK_Instance::VK_Instance()
{
    // Popluate the application info struct
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "WeaverEngine";
    appInfo.applicationVersion = VK_MAKE_API_VERSION(0, 1, 0, 0);
    appInfo.pEngineName = "Weaver";
    appInfo.engineVersion = VK_MAKE_API_VERSION(0, 1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    // Popluate the create info struct
    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    // Get the extensions count and name from the glfw and pass the information to createInfo struct
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    // No vulkan layers are activated
    createInfo.enabledLayerCount = 0;

#ifndef NDEBUG
    print_available_extension_names();
#endif

    // Create the actual Vulkan instance and pass the createInfo struct
    if (vkCreateInstance(&createInfo, nullptr, &m_instance) != VK_SUCCESS)
    {
        Debug::Exception("VK_Instance::ctor()::failed to create instance!");
    }
    else
    {
        Debug::Log(Log, "VK_Instance::ctor()::Created Vulkan Instance");
    }
}

VK_Instance::~VK_Instance()
{
    vkDestroyInstance(m_instance, nullptr);
}

void VK_Instance::print_available_extension_names()
{
    // Check for available optional extensions 
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

    Debug::Log(Success, "\t:::::Available extensions:::::");

    for (const auto& extension : extensions)
    {
        Debug::Log(Success, "\t%s", extension.extensionName);
    }
}
