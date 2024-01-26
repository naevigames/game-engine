#pragma once

namespace vk
{
    class SurfaceDetails
    {
    public:
        VkSurfaceCapabilitiesKHR capabilities;
        VkSurfaceFormatKHR       current_format;
    };
}