module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

module creepy.graphics.graphicsengine;

import creepy.graphics.graphicsdevice;

namespace Creepy{
    void* GraphicsEngine::createSwapChain(const SwapChainDesc& swapChainDesc) const {
        return m_graphicsDevice.createSwapChain(swapChainDesc);
    }
}