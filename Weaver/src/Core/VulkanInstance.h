#pragma once

#include "vulkan/vulkan.h"
class VulkanInstance
{
public:
	VulkanInstance();
	~VulkanInstance();

private:
	void create_instance();
	void print_available_extension_names();

	VkInstance m_instance;
};

