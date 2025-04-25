module;

#include <d3d11.h>
#include <wrl.h>

export module creepy.graphics.rendersystem;


namespace Creepy{

    export class RenderSystem{
        public:
            RenderSystem();

        private:
            Microsoft::WRL::ComPtr<ID3D11Device> m_logicalDevice{nullptr};
            Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_deviceContext{nullptr};
    };

}
