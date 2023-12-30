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

    void Buffer::source(const BufferData& data) const
    {
        glBufferData(_target, data._size, data._ptr, GL_STATIC_DRAW); // TODO usage to be a param of the function?
    }
}