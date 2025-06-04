module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

#include <bits/c++config.h>
#include <d3d11.h>
#include <wrl.h>

module creepy.graphics.graphicsdevice;

import creepy.core.logger;

import std;

namespace Creepy{

    GraphicsDevice::GraphicsDevice(){
        UINT createDeviceFlags{};

        // This suck
        // createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;

        D3D_FEATURE_LEVEL featureLevel{};

        auto res = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags, nullptr, 0, D3D11_SDK_VERSION, &m_logicalDevice, &featureLevel, &m_immediateDeviceContext);

        if(FAILED(res)){
            Log::Error("Failed to create logical device");
            // std::println("Failed to create logical device");
        }
        
        res = m_logicalDevice->QueryInterface(IID_PPV_ARGS(&m_dxgiDevice));

        if(FAILED(res)){
            Log::Error("Failed to QueryInterface");
        }

        res = m_dxgiDevice->GetParent(IID_PPV_ARGS(&m_dxgiAdapter));

        if(FAILED(res)){
            Log::Error("Failed to m_dxgiDevice GetParent");
        }

        res = m_dxgiAdapter->GetParent(IID_PPV_ARGS(&m_dxgiFactory));

        if(FAILED(res)){
            Log::Error("Failed to m_dxgiAdapter GetParent");
        }
    }

    
    SwapChain* GraphicsDevice::createSwapChain(const SwapChainDesc& swapChainDesc) const {
        return new SwapChain{m_logicalDevice.Get(), m_dxgiFactory.Get(), swapChainDesc};
    }

    DeviceContext* GraphicsDevice::createDeviceContext() const {
        return new DeviceContext{m_logicalDevice.Get()};
    }

    ShaderBinary* GraphicsDevice::compileShader(const ShaderDesc& shaderDesc) const {
        return new ShaderBinary{shaderDesc};
    }

    GraphicsPipelineState* GraphicsDevice::createGraphicsPipelineState(const GraphicsPipelineStateDesc& graphicPipelineStateDesc) const {
        return new GraphicsPipelineState{m_logicalDevice.Get(), graphicPipelineStateDesc};
    }

    VertexBuffer* GraphicsDevice::createVertexBuffer(std::span<const Vec3> vertices) const {
        return new VertexBuffer{m_logicalDevice.Get(), vertices};
    }

    void GraphicsDevice::executeCommandList(DeviceContext& deviceContext) {
        Microsoft::WRL::ComPtr<ID3D11CommandList> commandList{nullptr};
        auto res = deviceContext.getNativeHandle()->FinishCommandList(FALSE, &commandList);

        if(FAILED(res)){
            Log::Error("Failed to GetCommandList");
        }

        m_immediateDeviceContext->ExecuteCommandList(commandList.Get(), FALSE);

    }
}