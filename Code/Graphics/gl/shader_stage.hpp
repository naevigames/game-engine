#pragma once

#include "base/object.hpp"

namespace gl
{
    class ShaderStage final : public base::Object<uint32_t>
    {
    public:
        friend class Shader;

        void create(int32_t type);
        void release();

        void source(const char* data) const;
        void status()                 const;
    };
}