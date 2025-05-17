module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

#include <windows.h>

module creepy.game.game;


namespace Creepy{

    void Game::Run(){
        MSG message{};

        while(m_isRunning){
            while(PeekMessageA(&message, nullptr, 0, 0, PM_REMOVE)){

                if(message.message == WM_QUIT){
                    m_isRunning = false;
                }

                TranslateMessage(&message);
                DispatchMessageA(&message);
            }

            Sleep(1);
        }
    }

}