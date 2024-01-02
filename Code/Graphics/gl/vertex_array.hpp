#pragma once

#include "base/object.hpp"

namespace gl
{
    class VertexArray final : public base::Object<uint32_t>
    {
    public:
        void create();
        void release();

        void bind() const;
    };
}