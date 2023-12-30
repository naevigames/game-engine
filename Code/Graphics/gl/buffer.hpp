#pragma once

#include "base/object.hpp"
#include "buffer_data.hpp"

namespace gl
{
    class Buffer final : public base::Object<uint32_t>
    {
    public:
        Buffer(uint32_t target);

        void create();
        void release();

        void bind() const;
        void source(const BufferData& data) const;

    private:
        uint32_t _target;
    };
}