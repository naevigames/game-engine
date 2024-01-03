#pragma once

#include "base/object.hpp"

namespace vk
{
    class Instance final : private base::Object<VkInstance>
    {
    public:
        void create();
        void release();

        [[nodiscard]] VkInstance handle() const; // TODO remove in the future?
    };
}