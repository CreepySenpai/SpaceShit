module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

#include <d3d11.h>
#include <wrl.h>

export module creepy.graphics.rendersystem;

export import creepy.graphics.swapchain;

namespace Creepy{

    export class RenderSystem{
        public:
            RenderSystem();

            SwapChain* createSwapChain(const SwapChainDesc& swapChainDesc) const;

        private:
            Microsoft::WRL::ComPtr<ID3D11Device> m_logicalDevice{nullptr};
            Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_deviceContext{nullptr};
            Microsoft::WRL::ComPtr<IDXGIDevice> m_dxgiDevice{nullptr};
            Microsoft::WRL::ComPtr<IDXGIAdapter> m_dxgiAdapter{nullptr};
            Microsoft::WRL::ComPtr<IDXGIFactory> m_dxgiFactory{nullptr};
    };

}
