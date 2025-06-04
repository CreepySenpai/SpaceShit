module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

#include <bits/c++config.h>
#include <d3d11.h>
#include <wrl.h>

export module creepy.graphics.devicecontext;

import creepy.graphics.swapchain;

import creepy.core.vector;

import creepy.graphics.graphicspipelinestate;

import creepy.graphics.buffer;

namespace Creepy{

    export class DeviceContext{
        public:
            DeviceContext(ID3D11Device* logicalDevice);

            void clearAndSetBackBuffer(const SwapChain& swapChain, const Vec4& color);
            
            void setGraphicsPipelineState(const GraphicsPipelineState& graphicsPipelineState);

            void bindVertexBuffer(const VertexBuffer& vertexBuffer);

            void setViewport(float width, float height);

            void drawTriangles(uint32_t vertexCount, uint32_t startVertex);

            ID3D11DeviceContext* getNativeHandle() const;
            
        private:
            Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_deferDeviceContext{nullptr};
    };

}