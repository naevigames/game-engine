#include "vertex_array.hpp"

namespace gl
{
    void VertexArray::create()
    {
        glCreateVertexArrays(1, &_handle);
    }

    void VertexArray::release()
    {
        glDeleteVertexArrays(1, &_handle);
    }

    void VertexArray::bind() const
    {
        glBindVertexArray(_handle);
    }
}