#include "platform.hpp"

namespace win32
{
    LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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

    void Platform::init()
    {
        WNDCLASS wc
        {
            .style         = CS_HREDRAW | CS_VREDRAW,
            .lpfnWndProc   = WindowProc,
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
        MSG msg = { };
        while (GetMessage(&msg, NULL, 0, 0) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}