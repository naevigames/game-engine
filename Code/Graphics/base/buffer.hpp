#pragma once

#include "buffer_data.hpp"
#include "base/object.hpp"

namespace base
{
    class Buffer : public base::Object<uint32_t>
    {
    public:
        template<typename type> static BufferData make_data(const std::vector<type>& buffer)
        {
            return { buffer.data(), static_cast<uint32_t>(buffer.size() * sizeof(type)) };
        }
        template<typename type> static BufferData make_data(const type* ptr)
        {
            return { ptr, sizeof(type) };
        }
    };
}