#pragma once

#include "base/object.hpp"

namespace gl
{
    class Shader
    {
    public:
        Shader();

        void create(int32_t type);
        void release();
        void compile();

        void source(const char* data);

        [[nodiscard]] uint32_t handle() const;

    private:
        void status();

        uint32_t _handle;
    };
}