module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

#include <d3d11.h>
#include <wrl.h>

export module creepy.graphics.swapchain;

export import creepy.core.resourcedesc;

namespace Creepy{

    export class SwapChain{
        public:
            SwapChain(ID3D11Device* logicalDevice, IDXGIFactory* factory, const SwapChainDesc& swapChainDesc);

        private:
            ID3D11Device* m_logicalDevice{nullptr};
            IDXGIFactory* m_factory{nullptr};
            Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain{nullptr};
    };
}