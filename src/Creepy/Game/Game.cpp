module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Game/Game.cppm>
    #include <Creepy/Graphics/GraphicsEngine.cppm>
    #include <Creepy/Window/Window.cppm>
    #include <Creepy/Core/Logger.cppm>
#endif

#include <print>

module creepy.game.game;

import creepy.core.logger;

namespace Creepy{

    Game::Game() : m_graphicsEngine{}, m_window{1280, 720}{
        Log::Info("Game init ok: {}", 10);
    }

}