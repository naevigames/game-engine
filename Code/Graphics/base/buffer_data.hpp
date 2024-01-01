#pragma once

namespace base
{
    class BufferData
    {
    public:
        BufferData(const void* ptr, uint32_t size) : _ptr { ptr }, _size { size }
        {
        }

        [[nodiscard]] const void* ptr() const
        {
            return _ptr;
        }
        [[nodiscard]] uint32_t   size() const
        {
            return _size;
        }

    private:
        const void* _ptr;
        uint32_t    _size;
    };
}