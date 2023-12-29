#include "buffer.hpp"

namespace gl
{
    Buffer::Buffer(uint32_t target)
        : _target { target }
    {
    }

    void Buffer::create()
    {
        glGenBuffers(1, &_handle);
    }

    void Buffer::release()
    {
        glDeleteBuffers(1, &_handle);
    }

    void Buffer::bind() const
    {
        glBindBuffer(_target, _handle);
    }

    void Buffer::source(void* data, int32_t size) const
    {
        glBufferData(_target, size, data, GL_STATIC_DRAW); // TODO usage to be a param of the function?
    }
}