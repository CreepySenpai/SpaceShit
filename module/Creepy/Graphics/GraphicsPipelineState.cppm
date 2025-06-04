module;

#include <bits/c++config.h>
#include <d3d11.h>
#include <wrl.h>

export module creepy.graphics.graphicspipelinestate;

export import creepy.graphics.shaderbinary;

namespace Creepy{
    
    export struct GraphicsPipelineStateDesc{
        const ShaderBinary& vertexShader;
        const ShaderBinary& fragmentShader;
    };

    export class GraphicsPipelineState{
        public:
            GraphicsPipelineState(ID3D11Device* logicalDevice, const GraphicsPipelineStateDesc& graphicsPipelineStateDesc);

            ID3D11VertexShader* getVertexShader() const;
            ID3D11PixelShader* getFragmentShader() const;

            ID3D11InputLayout* getPipelineLayout() const;
            
        private:
            Microsoft::WRL::ComPtr<ID3D11VertexShader> m_vertexShader{nullptr};
            Microsoft::WRL::ComPtr<ID3D11PixelShader> m_fragmentShader{nullptr};
            Microsoft::WRL::ComPtr<ID3D11InputLayout> m_pipelineLayout{nullptr};
    };

}