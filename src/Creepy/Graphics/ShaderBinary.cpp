module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif


// #include <Creepy/Dump.hpp>

#include <bits/c++config.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <wrl.h>

module creepy.graphics.shaderbinary;

import std;
import creepy.core.logger;

namespace{
    static const char* GetShaderTypeName(Creepy::ShaderType shaderType){
        if(shaderType == Creepy::ShaderType::Vertex){
            return "vs_5_0";
        }
        else if(shaderType == Creepy::ShaderType::Fragment){
            return "ps_5_0";
        }

        return "";
    }
}

namespace Creepy{

    ShaderBinary::ShaderBinary(const ShaderDesc& shaderDesc){
        constexpr UINT compileFlags{D3DCOMPILE_DEBUG};
        
        Log::Info("Gonna compile size: {}", shaderDesc.srcCode.size());
        Microsoft::WRL::ComPtr<ID3DBlob> errorBlob{nullptr};

        auto res = D3DCompile(shaderDesc.srcCode.data(), shaderDesc.srcCode.size(), shaderDesc.srcName.data(), nullptr, nullptr, "main", 
            GetShaderTypeName(shaderDesc.shaderType), compileFlags, 0, &m_shaderBlob, &errorBlob);
    
        const char* errorMessage = errorBlob != nullptr ? static_cast<const char*>(errorBlob->GetBufferPointer()) : nullptr;
        
        if(FAILED(res)){
            if(errorMessage){
                Log::Error("Failed to compile shader {}: {}", shaderDesc.srcName, errorMessage);
            }
            else{
                Log::Error("Failed to compile shader: {}", shaderDesc.srcName);
            }
        }

        
    }

    ShaderData ShaderBinary::getShaderData() const {
        return {
            m_shaderBlob->GetBufferPointer(),
            m_shaderBlob->GetBufferSize()
        };
    }

}