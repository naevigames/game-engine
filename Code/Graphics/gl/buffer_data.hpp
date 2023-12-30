#pragma once

namespace gl
{
    class BufferData
    {
    public:
        friend class Buffer;

        BufferData(const void* ptr, uint32_t size) : _ptr { ptr }, _size { size }
        {
        }

        // TODO move make_data into buffer class base class??
        // in this way you can move buffer_data outside from gl? or put it in the base folder

        template<typename type>
        static BufferData make_data(const std::vector<type>& buffer)
        {
            return { buffer.data(), static_cast<uint32_t>(buffer.size() * sizeof(type)) };
        }

        template<typename type>
        static BufferData make_data(const type* ptr)
        {
            return { ptr, sizeof(type) };
        }

    private:
        const void* _ptr;
        uint32_t    _size;
    };
}