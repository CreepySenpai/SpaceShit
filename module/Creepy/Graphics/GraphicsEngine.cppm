module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

export module creepy.graphics.graphicsengine;

export import creepy.core.resourcedesc;

import creepy.graphics.graphicsdevice;

namespace Creepy{
    
    export class GraphicsEngine{
        public:
            GraphicsEngine();
            ~GraphicsEngine();

            SwapChain* createSwapChain(const SwapChainDesc& swapChainDesc) const;

            void render(SwapChain& swapChain);
            
        private:
            GraphicsDevice m_graphicsDevice;
            DeviceContext* m_deviceContext{nullptr};
            GraphicsPipelineState* m_graphicsPipelineState{nullptr};
            VertexBuffer* m_vertexBuffer{nullptr};
    };

}