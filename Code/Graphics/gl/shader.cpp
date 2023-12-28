#include "shader.hpp"

namespace gl
{
    void Shader::create()
    {
        _handle = glCreateProgram();
    }

    void Shader::release()
    {
        glDeleteProgram(_handle);
    }

    void Shader::compile() const
    {
        glLinkProgram(_handle);

        status();
    }

    void Shader::attach(const ShaderStage& shader)
    {
        glAttachShader(_handle, shader._handle);
    }

    void Shader::detach(const ShaderStage& shader)
    {
        glDetachShader(_handle, shader._handle);
    }

    void Shader::bind() const
    {
        glUseProgram(_handle);
    }

    void Shader::status() const
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