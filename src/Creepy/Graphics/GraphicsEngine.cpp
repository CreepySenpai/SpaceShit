module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

module creepy.graphics.graphicsengine;

import creepy.graphics.graphicsdevice;

namespace Creepy{

    GraphicsEngine::GraphicsEngine() {
        m_deviceContext = m_graphicsDevice.createDeviceContext();

        constexpr char vertexShaderCode[]{
            R"(
                float4 main(float3 pos : MY_POSITION) : SV_Position {
                    return float4(pos.x, pos.y, pos.z, 1.0);
                }
            )"
        };

        constexpr char fragmentShaderCode[]{
            R"(
                float4 main() : SV_Target {
                    return float4(1.0, 1.0, 1.0, 1.0);
                }
            )"
        };

        auto vertexBin = m_graphicsDevice.compileShader({"NahBro", vertexShaderCode, ShaderType::Vertex});

        auto fragmentBin = m_graphicsDevice.compileShader({"NahBro", fragmentShaderCode, ShaderType::Fragment});

        m_graphicsPipelineState = m_graphicsDevice.createGraphicsPipelineState({*vertexBin, *fragmentBin});

        delete vertexBin;
        vertexBin = nullptr;
        delete fragmentBin;
        fragmentBin = nullptr;
        
        constexpr Vec3 vertices[]{
            {-0.5f, -0.5f, 0.0f},
            {0.0f, 0.5f, 0.0f},
            {0.5f, -0.5f, 0.0f}
        };

        m_vertexBuffer = m_graphicsDevice.createVertexBuffer(vertices);
    }

    GraphicsEngine::~GraphicsEngine() {
        delete m_vertexBuffer;
        m_vertexBuffer = nullptr;

        delete m_graphicsPipelineState;
        m_graphicsPipelineState = nullptr;

        delete m_deviceContext;
        m_deviceContext = nullptr;
    }

    SwapChain* GraphicsEngine::createSwapChain(const SwapChainDesc& swapChainDesc) const {
        return m_graphicsDevice.createSwapChain(swapChainDesc);
    }

    void GraphicsEngine::render(SwapChain& swapChain) {

        m_deviceContext->clearAndSetBackBuffer(swapChain, {1.0f, 0.0f, 0.0f, 1.0f});

        m_deviceContext->setGraphicsPipelineState(*m_graphicsPipelineState);
        m_deviceContext->setViewport(swapChain.getWidth(), swapChain.getHeight());

        m_deviceContext->bindVertexBuffer(*m_vertexBuffer);

        // Draw call
        m_deviceContext->drawTriangles(m_vertexBuffer->getVertexCount(), 0);

        m_graphicsDevice.executeCommandList(*m_deviceContext);

        swapChain.present(false);
    }

}