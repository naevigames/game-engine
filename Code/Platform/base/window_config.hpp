#pragma once

namespace base
{
    using  window_hint = std::pair<int32_t, int32_t>;

    struct window_config
    {
        std::string title;

        int32_t width;
        int32_t height;
    };
}