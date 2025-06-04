module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

module creepy.game.game;

import creepy.graphics.swapchain;

import creepy.core.logger;

namespace Creepy{

    Game::Game() : m_graphicsEngine{}, m_window{1280, 720}{
        Log::Info("Game init ok: {}", 10);

        const SwapChainDesc swapChainDesc{
            .width = 1280,
            .height = 720,
            .windowHandle = m_window.getWindowHandle()
        };

        m_window.setSwapChain(m_graphicsEngine.createSwapChain(swapChainDesc));
    }

    void Game::update() {
        const auto swapChain = m_window.getSwapChain();
        m_graphicsEngine.render(*swapChain);
    }

}