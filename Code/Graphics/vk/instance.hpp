#pragma once

#include "base/object.hpp"

namespace vk
{
    class Instance final : public base::Object<VkInstance>
    {
    public:
        void create();
        void destroy();
    };
}