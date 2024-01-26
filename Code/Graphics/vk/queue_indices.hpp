#pragma once

namespace vk
{
    class QueueIndices
    {
    public:
        friend class PhysicalDevice;

        [[nodiscard]] std::vector<uint32_t> vec() const;
        [[nodiscard]] std::set<uint32_t>    set() const;

        [[nodiscard]] uint32_t graphics() const;
        [[nodiscard]] uint32_t present()  const;

    private:
        uint32_t _graphics = -1;
        uint32_t _present  = -1;
    };
}