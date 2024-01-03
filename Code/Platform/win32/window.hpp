#pragma once

#include "base/window.hpp"

namespace win32
{
    class Window final : public base::Window
    {
    public:
        friend class PlatformManager;

        void create(const base::window_config& config) final;
        void destroy()  final;
        void activate() final;

        void swap_buffers() const final;
        void sync_buffers() const final;

        void hint(const base::window_hint& hint) final;

    private:
        HWND _handle;
    };
}