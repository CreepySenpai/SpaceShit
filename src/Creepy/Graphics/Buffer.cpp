module;

#include <bits/c++config.h>
#include <d3d11.h>
#include <wrl.h>

module creepy.graphics.buffer;

import std;
import creepy.core.logger;

namespace Creepy{

    VertexBuffer::VertexBuffer(ID3D11Device* logicalDevice, std::span<const Vec3> vertices) : m_vertexCount{vertices.size()} {
        D3D11_BUFFER_DESC bufferDesc{};
        bufferDesc.ByteWidth = vertices.size_bytes();
        bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

        D3D11_SUBRESOURCE_DATA bufferData{};
        bufferData.pSysMem = vertices.data();

        auto res = logicalDevice->CreateBuffer(&bufferDesc, &bufferData, &m_vertexBuffer);
    
        if(FAILED(res)){
            Log::Error("Failed to create vertex buffer");
        }
    }

    uint32_t VertexBuffer::getVertexCount() const {
        return m_vertexCount;
    }

    ID3D11Buffer* VertexBuffer::getNativeHandle() const {
        return m_vertexBuffer.Get();
    }

}