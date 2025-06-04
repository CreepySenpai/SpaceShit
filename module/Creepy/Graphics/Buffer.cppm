module;

#include <bits/c++config.h>
#include <d3d11.h>
#include <wrl.h>

export module creepy.graphics.buffer;

export import creepy.core.vector;

export import creepy.core.type;

import std;

namespace Creepy{

    export class VertexBuffer{
        public:
            VertexBuffer(ID3D11Device* logicalDevice, std::span<const Vec3> vertices);
            
            uint32_t getVertexCount() const;

            ID3D11Buffer* getNativeHandle() const;
        private:
            Microsoft::WRL::ComPtr<ID3D11Buffer> m_vertexBuffer{nullptr};
            uint32_t m_vertexCount{};
    };

}