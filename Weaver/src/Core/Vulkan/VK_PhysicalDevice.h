#pragma once

#include "vulkan/vulkan.h"
#include <optional>
class VK_PhysicalDevice
{
public:
	VK_PhysicalDevice(VkInstance instance);

	inline VkPhysicalDevice Get() const { return m_physicalDevice; }

private:
	bool is_device_suitable(VkPhysicalDevice device);
	std::optional<uint32_t> find_queue_families(VkPhysicalDevice device);

	std::optional<uint32_t> m_graphicsFamily;
	VkPhysicalDevice m_physicalDevice;
};

