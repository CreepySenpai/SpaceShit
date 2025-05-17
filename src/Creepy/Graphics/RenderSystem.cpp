module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

#include <bits/c++config.h>
#include <d3d11.h>
#include <wrl.h>

module creepy.graphics.rendersystem;

import creepy.core.logger;

namespace Creepy{

    RenderSystem::RenderSystem(){
        UINT createDeviceFlags{};

        // This suck
        // createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;

        D3D_FEATURE_LEVEL featureLevel{};

        auto res = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags, nullptr, 0, D3D11_SDK_VERSION, &m_logicalDevice, &featureLevel, &m_deviceContext);

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

    
    SwapChain* RenderSystem::createSwapChain(const SwapChainDesc& swapChainDesc) const {
        return new SwapChain{m_logicalDevice.Get(), m_dxgiFactory.Get(), swapChainDesc};
    }
}