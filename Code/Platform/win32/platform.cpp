#include "platform.hpp"
#include "platform_manager.hpp"
#include "window_events.hpp"

namespace win32
{
    void Platform::init()
    {
        WNDCLASS wc
        {
            .style         = CS_HREDRAW | CS_VREDRAW,
            .lpfnWndProc   = WindowEvents::on_event,
            .hInstance     = GetModuleHandle(nullptr),
            .lpszClassName = "win32_class"
        };

        RegisterClass(&wc);
    }

    void Platform::release()
    {
        UnregisterClass("win32_class", GetModuleHandle(nullptr));
    }

    void Platform::poll_events() const
    {
        MSG msg;

        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                PlatformManager::instance().shutdown();
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
    }
}