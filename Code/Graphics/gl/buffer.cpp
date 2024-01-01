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

    void Buffer::source(const base::BufferData& data) const
    {
        glBufferData(_target, data.size(), data.ptr(), GL_STATIC_DRAW); // TODO usage to be a param of the function?
    }
}