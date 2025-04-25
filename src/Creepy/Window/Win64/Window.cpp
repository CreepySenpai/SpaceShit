module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Window/Window.cppm>
    #include <Creepy/Core/Logger.cppm>
#endif

#include <cstdint>
#include <print>
#include <windows.h>

module creepy.window.window;

import creepy.core.logger;


namespace {
    LRESULT CALLBACK WindowProcCallback(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam){
        switch(message){
            case WM_CLOSE:{
                PostQuitMessage(0);
                break;
            }

            default:{
                return DefWindowProcA(hwnd, message, wparam, lparam);
            }
        }

        return 0;
    }
}

namespace Creepy{
    Window::Window(uint32_t width, uint32_t height) : m_width{width}, m_height{height}{
        WNDCLASSEXA windClass{};
        windClass.cbSize = sizeof(WNDCLASSEXA);
        windClass.lpszClassName = "MyWindow";
        windClass.lpfnWndProc = WindowProcCallback;
        windClass.hInstance = GetModuleHandleA(nullptr);

        auto windowID = RegisterClassExA(&windClass);

        if(!windowID){
            Log::Error("Failed to register wind class");
        }

        RECT windRec{0, 0, width, height};
        AdjustWindowRect(&windRec, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

        m_windowHandle = CreateWindowExA(0, windClass.lpszClassName, "Sucker", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, windRec.right - windRec.left, windRec.bottom - windRec.top, nullptr, nullptr, windClass.hInstance, nullptr);
    
        if(!m_windowHandle){
            Log::Error("Failed to create window handle");
        }

        ShowWindow(static_cast<HWND>(m_windowHandle), SW_SHOW);
    }

    Window::compl Window() {
        DestroyWindow(static_cast<HWND>(m_windowHandle));
    }
}