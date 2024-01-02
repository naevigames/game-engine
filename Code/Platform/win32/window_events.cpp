#include "window_events.hpp"
#include "platform_manager.hpp"
#include "screen.hpp"

namespace win32
{
    LRESULT WindowEvents::on_event(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
    {
        switch (msg)
        {
            case WM_CLOSE:
            {
                PlatformManager::instance().shutdown();
                return 0;
            }
            case WM_SIZE:
            {
                const int width  = LOWORD(lparam);
                const int height = HIWORD(lparam);

                Screen::set_size({ width, height });
                return 0;
            }
        }

        return DefWindowProc(hwnd, msg, wparam, lparam);
    }
}