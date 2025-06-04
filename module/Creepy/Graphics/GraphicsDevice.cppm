module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

#include <bits/c++config.h>
#include <d3d11.h>
#include <wrl.h>

export module creepy.graphics.graphicsdevice;

export import creepy.graphics.devicecontext;

export import creepy.graphics.swapchain;

export import creepy.graphics.shaderbinary;

export import creepy.graphics.graphicspipelinestate;

export import creepy.graphics.buffer;

import std;

namespace Creepy{

    export class GraphicsDevice{
        public:
            GraphicsDevice();

            SwapChain* createSwapChain(const SwapChainDesc& swapChainDesc) const;

            DeviceContext* createDeviceContext() const;

            ShaderBinary* compileShader(const ShaderDesc& shaderDesc) const;
            
            GraphicsPipelineState* createGraphicsPipelineState(const GraphicsPipelineStateDesc& graphicPipelineStateDesc) const;

            VertexBuffer* createVertexBuffer(std::span<const Vec3> vertices) const;

            void executeCommandList(DeviceContext& deviceContext);
            
        private:
            Microsoft::WRL::ComPtr<ID3D11Device> m_logicalDevice{nullptr};
            Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_immediateDeviceContext{nullptr};
            Microsoft::WRL::ComPtr<IDXGIDevice> m_dxgiDevice{nullptr};
            Microsoft::WRL::ComPtr<IDXGIAdapter> m_dxgiAdapter{nullptr};
            Microsoft::WRL::ComPtr<IDXGIFactory> m_dxgiFactory{nullptr};
    };

}
