#pragma once

#include "base/object.hpp"

namespace gl
{
    class Shader final : public base::Object<uint32_t>
    {
    public:
        friend class Program;

        void create(int32_t type);
        void release();
        void compile();

        void source(const char* data);

    private:
        void status();
    };
}