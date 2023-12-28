#pragma once

#include "shader.hpp"

namespace gl
{
    class Program final : public base::Object<uint32_t>
    {
    public:
        void create();
        void release();
        void compile();

        void attach(const Shader& shader);
        void detach(const Shader& shader);

        void bind();

    private:
        void status();
    };
}