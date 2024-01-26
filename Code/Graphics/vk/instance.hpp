#pragma once

#include "base/object.hpp"

namespace vk
{
    class PhysicalDevice;
    class Instance final : public base::Object<VkInstance>
    {
    public:
        void create();
        void destroy();

        [[nodiscard]] PhysicalDevice find_device() const;
    };
}