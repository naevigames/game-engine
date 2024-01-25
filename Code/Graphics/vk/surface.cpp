#include "surface.hpp"

namespace vk
{
    void Surface::create(const Instance& instance, std::any handle)
    {
        VkWin32SurfaceCreateInfoKHR vk_surface_create_info
        {
            .sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,
            .hinstance = GetModuleHandle(nullptr),
            .hwnd      = std::any_cast<HWND>(handle)
        };

        vkCreateWin32SurfaceKHR(instance._handle, &vk_surface_create_info, nullptr, &_handle);
    }

    void Surface::destroy(const Instance& instance)
    {
        vkDestroySurfaceKHR(instance._handle, _handle, nullptr);
    }
}