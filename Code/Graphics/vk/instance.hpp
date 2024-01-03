#pragma once

#include "base/object.hpp"

namespace vk
{
    class Instance final : public base::Object<VkInstance>
    {
    public:
        friend class Surface;

        void create();
        void release();

        [[nodiscard]] VkInstance handle() const; // TODO remove in the future?
    };
}