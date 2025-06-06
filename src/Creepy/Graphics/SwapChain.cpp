module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

#include <bits/c++config.h>
#include <d3d11.h>
#include <wrl.h>

module creepy.graphics.swapchain;

import creepy.core.logger;

namespace Creepy{

    SwapChain::SwapChain(ID3D11Device* logicalDevice, IDXGIFactory* factory, const SwapChainDesc& swapChainDesc) : m_logicalDevice{logicalDevice}, m_factory{factory},
        m_width{static_cast<float>(swapChainDesc.width)}, m_height{static_cast<float>(swapChainDesc.height)}{
        
        DXGI_SWAP_CHAIN_DESC swapChainCreateInfo{};
        swapChainCreateInfo.BufferDesc.Width = swapChainDesc.width;
        swapChainCreateInfo.BufferDesc.Height = swapChainDesc.height;
        swapChainCreateInfo.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        swapChainCreateInfo.BufferCount = 2u;
        swapChainCreateInfo.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChainCreateInfo.OutputWindow = static_cast<HWND>(swapChainDesc.windowHandle);
        swapChainCreateInfo.SampleDesc.Count = 1;
        swapChainCreateInfo.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
        swapChainCreateInfo.Windowed = TRUE;
        
        auto res = m_factory->CreateSwapChain(m_logicalDevice, &swapChainCreateInfo, &m_swapChain);
    
        if(FAILED(res)){
            Log::Error("Failed to create window handle");
        }

        // Create render target
        reloadBuffers();
    }

    void SwapChain::reloadBuffers() {
        Microsoft::WRL::ComPtr<ID3D11Texture2D> buffer{nullptr};

        auto res = m_swapChain->GetBuffer(0, IID_PPV_ARGS(&buffer));

        if(FAILED(res)){
            Log::Error("Failed to GetBuffer");
        }

        res = m_logicalDevice->CreateRenderTargetView(buffer.Get(), nullptr, &m_renderTargetView);
    
        if(FAILED(res)){
            Log::Error("Failed to CreateRenderTargetView");
        }
    }

    ID3D11RenderTargetView* SwapChain::getrenderTargetView() const {
        return m_renderTargetView.Get();
    }

    void SwapChain::present(bool isEnableVsync) {
        auto res = m_swapChain->Present(isEnableVsync, 0);

        if(FAILED(res)){
            Log::Error("Failed to Present");
        }
    }

    float SwapChain::getWidth() const {
        return m_width;
    }

    float SwapChain::getHeight() const {
        return m_height;
    }

}