#include "program.hpp"

namespace gl
{
    void Program::create()
    {
        _handle = glCreateProgram();
    }

    void Program::release()
    {
        glDeleteProgram(_handle);
    }

    void Program::compile()
    {
        glLinkProgram(_handle);

        status();
    }

    void Program::attach(const Shader& shader)
    {
        glAttachShader(_handle, shader._handle);
    }

    void Program::detach(const Shader& shader)
    {
        glDetachShader(_handle, shader._handle);
    }

    void Program::bind()
    {
        glUseProgram(_handle);
    }

    void Program::status()
    {
        int32_t success;
        glGetProgramiv(_handle, GL_LINK_STATUS, &success);

        if (!success)
        {
            char info[512];
            glGetProgramInfoLog(_handle, 512, nullptr, info);

            std::cout << "program compilation failed\n" << info << "\n";
        }
    }
}