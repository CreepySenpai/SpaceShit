module;

#include <bits/c++config.h>
#include <d3d11.h>
#include <wrl.h>

module creepy.graphics.graphicspipelinestate;

import creepy.core.logger;

import std;

namespace Creepy{

    GraphicsPipelineState::GraphicsPipelineState(ID3D11Device* logicalDevice, const GraphicsPipelineStateDesc& graphicsPipelineStateDesc){
        auto vertexShaderBinaryData = graphicsPipelineStateDesc.vertexShader.getShaderData();
        auto fragmentShaderBinaryData = graphicsPipelineStateDesc.fragmentShader.getShaderData();
        
        constexpr D3D11_INPUT_ELEMENT_DESC elementDescs[]{
            {"MY_POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0}
        };

        auto res = logicalDevice->CreateInputLayout(elementDescs, std::size(elementDescs), vertexShaderBinaryData.data, vertexShaderBinaryData.size, &m_pipelineLayout);

        if(FAILED(res)){
            Log::Error("Failed create graphic pipeline layout");
        }

        res = logicalDevice->CreateVertexShader(vertexShaderBinaryData.data, vertexShaderBinaryData.size, nullptr, &m_vertexShader);
    
        if(FAILED(res)){
            Log::Error("Failed create vertex shader");
        }

        logicalDevice->CreatePixelShader(fragmentShaderBinaryData.data, fragmentShaderBinaryData.size, nullptr, &m_fragmentShader);
    
        if(FAILED(res)){
            Log::Error("Failed create fragment shader");
        }
    }

    ID3D11VertexShader* GraphicsPipelineState::getVertexShader() const{
        return m_vertexShader.Get();
    }
    
    ID3D11PixelShader* GraphicsPipelineState::getFragmentShader() const {
        return m_fragmentShader.Get();
    }

    ID3D11InputLayout* GraphicsPipelineState::getPipelineLayout() const {
        return m_pipelineLayout.Get();
    }

}