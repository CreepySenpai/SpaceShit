module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Graphics/GraphicsEngine.cppm>
    #include <Creepy/Window/Window.cppm>
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
            GraphicsEngine m_graphicsEngine;
            Window m_window;
            bool m_isRunning{true};
    };

}