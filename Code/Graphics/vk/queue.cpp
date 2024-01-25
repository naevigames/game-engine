#include "queue.hpp"

namespace vk
{
    void Queue::find_queue(const Device& device, uint32_t family_index)
    {
        vkGetDeviceQueue(device._handle, family_index, 0, &_handle);
    }
}