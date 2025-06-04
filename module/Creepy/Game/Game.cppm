module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

export module creepy.game.game;

export import creepy.window.window;
export import creepy.graphics.graphicsengine;


namespace Creepy{

    export class Game{
        public:
            Game();

            void Run();

        private:
            void update();

        private:
            GraphicsEngine m_graphicsEngine;
            Window m_window;
            bool m_isRunning{true};
    };

}