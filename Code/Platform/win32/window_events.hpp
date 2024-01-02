#pragma once

namespace win32
{
    class WindowEvents
    {
    public:
        WindowEvents() = delete;

        static LRESULT CALLBACK on_event(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
    };
}