#pragma once

#include "base/buffer.hpp"

namespace gl
{
    class Buffer final : public base::Buffer
    {
    public:
        Buffer(uint32_t target);

        void create();
        void release();

        void bind() const;
        void source(const base::BufferData& data) const;

    private:
        uint32_t _target;
    };
}