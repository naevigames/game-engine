#pragma once

#include "shader_stage.hpp"

namespace gl
{
    class Shader final : public base::Object<uint32_t>
    {
    public:
        void create();
        void release();

        void attach(const ShaderStage& shader);
        void detach(const ShaderStage& shader);

        void bind()    const;
        void compile() const;
        void status()  const;
    };
}