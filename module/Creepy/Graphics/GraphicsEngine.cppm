module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

export module creepy.graphics.graphicsengine;

export import creepy.core.resourcedesc;

import creepy.graphics.rendersystem;

namespace Creepy{
    
    export class GraphicsEngine{
        public:
            void* createSwapChain(const SwapChainDesc& swapChainDesc) const;

        private:
            RenderSystem m_renderSystem;
    };

}