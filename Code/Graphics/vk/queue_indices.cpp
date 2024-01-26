#include "queue_indices.hpp"

namespace vk
{
    std::set<uint32_t> QueueIndices::set() const
    {
        return { _graphics, _present };
    }

    std::vector<uint32_t> QueueIndices::vec() const
    {
        return { _graphics, _present };
    }

    uint32_t QueueIndices::graphics() const
    {
        return _graphics;
    }

    uint32_t QueueIndices::present() const
    {
        return _present;
    }
}