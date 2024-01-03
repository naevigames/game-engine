#include "window.hpp"

namespace win32
{
    void Window::create(const base::window_config& config)
    {
        _handle = CreateWindowEx(0, "win32_engine_class", config.title.c_str(),
                                 WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                                 config.size.width, config.size.height, nullptr, nullptr,
                                 GetModuleHandle(nullptr), nullptr);
    }

    void Window::destroy()
    {
        DestroyWindow(_handle);
    }

    void Window::activate()
    {
        ShowWindow(_handle, SW_SHOW);
    }

    void Window::swap_buffers() const
    {
    }

    void Window::sync_buffers() const
    {
    }

    void Window::hint(const base::window_hint& hint)
    {
    }
}