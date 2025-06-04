module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

#include <bits/c++config.h>
#include <d3d11.h>
#include <wrl.h>

module creepy.graphics.devicecontext;

import creepy.graphics.swapchain;

import creepy.core.vector;

import creepy.graphics.graphicspipelinestate;

import creepy.graphics.buffer;

import creepy.core.logger;

namespace Creepy{

    DeviceContext::DeviceContext(ID3D11Device* logicalDevice) {
        auto res = logicalDevice->CreateDeferredContext(0, &m_deferDeviceContext);

        if(FAILED(res)){
            Log::Error("Failed to CreateDeferredContext");
        }
        
    }

    void DeviceContext::clearAndSetBackBuffer(const SwapChain& swapChain, const Vec4& color) {
        const float colorNah[]{
            color.x, color.y, color.z, color.w
        };

        
        auto renderTargetView = swapChain.getrenderTargetView();

        m_deferDeviceContext->ClearRenderTargetView(renderTargetView, colorNah);
        
        m_deferDeviceContext->OMSetRenderTargets(1, &renderTargetView, nullptr);
    }

    void DeviceContext::setGraphicsPipelineState(const GraphicsPipelineState& graphicsPipelineState) {
        m_deferDeviceContext->IASetInputLayout(graphicsPipelineState.getPipelineLayout());
        m_deferDeviceContext->VSSetShader(graphicsPipelineState.getVertexShader(), nullptr, 0);
        m_deferDeviceContext->PSSetShader(graphicsPipelineState.getFragmentShader(), nullptr, 0);
    }

    void DeviceContext::bindVertexBuffer(const VertexBuffer& vertexBuffer) {
        auto bufs = vertexBuffer.getNativeHandle();

        const UINT stride{sizeof(Vec3)};
        const UINT offset{};

        m_deferDeviceContext->IASetVertexBuffers(0, 1, &bufs, &stride, &offset);
    }

    void DeviceContext::setViewport(float width, float height) {

        D3D11_VIEWPORT viewPort{};
        viewPort.Width = width;
        viewPort.Height = height;
        viewPort.MinDepth = 0.0f;
        viewPort.MaxDepth = 1.0f;

        
        m_deferDeviceContext->RSSetViewports(1, &viewPort);
    }

    void DeviceContext::drawTriangles(uint32_t vertexCount, uint32_t startVertex) {
        m_deferDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        m_deferDeviceContext->Draw(vertexCount, startVertex);
    }

    ID3D11DeviceContext* DeviceContext::getNativeHandle() const {
        return m_deferDeviceContext.Get();
    }

}