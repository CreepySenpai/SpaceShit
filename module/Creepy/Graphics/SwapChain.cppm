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
            
            void present(bool isEnableVsync = false);

            float getWidth() const;

            float getHeight() const;

            ID3D11RenderTargetView* getrenderTargetView() const;

        private:
            void reloadBuffers();

        private:
            ID3D11Device* m_logicalDevice{nullptr};
            IDXGIFactory* m_factory{nullptr};
            Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain{nullptr};
            Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_renderTargetView{nullptr};
            float m_width{}, m_height{};
        };
}