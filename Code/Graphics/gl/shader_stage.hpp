#pragma once

#include "base/object.hpp"

namespace gl
{
    class ShaderStage final : public base::Object<uint32_t>
    {
    public:
        friend class Shader;

        void create(int32_t type); // TODO this part of the class? maybe you want to reuse the object
        void release();

        void source(const std::vector<char>& source) const;

    private:
        void status() const;
    };
}