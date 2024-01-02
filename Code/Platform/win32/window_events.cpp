#include "window_events.hpp"

namespace win32
{
    LRESULT WindowEvents::on_event(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg)
        {
            case WM_SIZE:
            {
                int width = LOWORD(lParam);  // Macro to get the low-order word.
                int height = HIWORD(lParam); // Macro to get the high-order word.

                // Respond to the message:
                //OnSize(hwnd, (UINT)wParam, width, height);
            }
            break;
        }

        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}