#include "shader_stage.hpp"

namespace gl
{
    void ShaderStage::create(int32_t type)
    {
        _handle = glCreateShader(type);
    }

    void ShaderStage::release()
    {
        glDeleteShader(_handle);
    }

    void ShaderStage::source(const char* data) const
    {
        glShaderSource(_handle, 1, &data, nullptr);
        glCompileShader(_handle);

        status();
    }

    void ShaderStage::status() const
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