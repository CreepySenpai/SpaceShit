module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Graphics/RenderSystem.cppm>
    #include <Creepy/Core/Logger.cppm>
#endif

#include <print>
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
        }
    }

    
}