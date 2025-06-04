module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

#include <bits/c++config.h>
#include <d3d11.h>
#include <wrl.h>

export module creepy.graphics.shaderbinary;

import std;

import creepy.core.type;

namespace Creepy{

    export enum class ShaderType : uint32_t {
        Vertex, Fragment
    };

    export struct ShaderDesc{
        std::string_view srcName;
        std::string_view srcCode;
        ShaderType shaderType;
    };

    export struct ShaderData{
        const void* data;
        uint32_t size;
    };

    export class ShaderBinary{
        public:
            ShaderBinary(const ShaderDesc& shaderDesc);

            ShaderData getShaderData() const;
            
        private:
            Microsoft::WRL::ComPtr<ID3DBlob> m_shaderBlob{nullptr};
    };

}