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

    void ShaderStage::source(const std::vector<char>& source) const
    {
        auto size = static_cast<int32_t>(source.size());
        auto data = source.data();

        glShaderSource(_handle, 1, &data, &size);
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