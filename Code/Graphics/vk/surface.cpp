#include "surface.hpp"

namespace vk
{
    void Surface::create(const Instance& instance, HWND handle)
    {
        VkWin32SurfaceCreateInfoKHR create_info
        {
            .sType     = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,
            .hinstance = GetModuleHandle(nullptr),
            .hwnd      = handle
        };

        vkCreateWin32SurfaceKHR(instance._handle, &create_info, nullptr, &_handle);
    }

    void Surface::release(const Instance& instance)
    {
        vkDestroySurfaceKHR(instance._handle, _handle, nullptr);
    }

    VkSurfaceKHR Surface::handle() const
    {
        return _handle;
    }
}