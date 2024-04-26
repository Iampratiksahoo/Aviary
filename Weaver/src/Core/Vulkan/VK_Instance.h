#pragma once

#include "vulkan/vulkan.h"
class VK_Instance
{
public:
	VK_Instance();
	~VK_Instance();
	
	inline VkInstance Get() const { return m_instance; }

private:
	void print_available_extension_names();

	VkInstance m_instance;
};

