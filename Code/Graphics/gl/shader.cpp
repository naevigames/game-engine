#include "shader.hpp"

namespace gl
{
    void Shader::create(int32_t type)
    {
        _handle = glCreateShader(type);
    }

    void Shader::release()
    {
        glDeleteShader(_handle);
    }

    void Shader::compile()
    {
        glCompileShader(_handle);

        status();
    }

    void Shader::source(const char* data)
    {
        glShaderSource(_handle, 1, &data, nullptr);
    }

    void Shader::status()
    {
        int32_t success;
        glGetShaderiv(_handle, GL_COMPILE_STATUS, &success);

        if (!success)
        {
            char info[512];
            glGetShaderInfoLog(_handle, 512, nullptr, info);

            std::cout << "shader compilation failed\n" << info << "\n";
        }
    }
}