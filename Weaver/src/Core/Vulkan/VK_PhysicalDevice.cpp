#include "VK_PhysicalDevice.h"

#include <map>
#include <vector>
#include <Utility/Debug.h>

VK_PhysicalDevice::VK_PhysicalDevice(VkInstance instance) : 
    m_physicalDevice(VK_NULL_HANDLE)
{
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

    if (deviceCount == 0)
    {
        Debug::Exception("VulkanInstance::ctor()::Failed to find GPUs with Vulkan support!");
    }

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

    for (const auto& device : devices)
    {
        if (is_device_suitable(device))
        {
            m_physicalDevice = device;
            break;
        }
    }

    if (m_physicalDevice == VK_NULL_HANDLE) 
    {
        Debug::Exception("VulkanInstance::ctor()::Failed to find a suitable GPU!");
    }
    else
    {
        Debug::Log(Log, "VulkanInstance::ctor()::Found a suitable GPU for the Engine");
    }
}

bool VK_PhysicalDevice::is_device_suitable(VkPhysicalDevice device)
{
    m_graphicsFamily = find_queue_families(device);
    return m_graphicsFamily.has_value();
}

std::optional<uint32_t> VK_PhysicalDevice::find_queue_families(VkPhysicalDevice device)
{
    std::optional<uint32_t> indices;
    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

    int i = 0;
    for (const auto& queueFamily : queueFamilies) 
    {
        if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) 
        {
            indices = i;
            break;
        }
        i++;
    }
    return indices;
}
