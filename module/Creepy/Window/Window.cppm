module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

export module creepy.window.window;

export import creepy.core.type;

import creepy.graphics.swapchain;

namespace Creepy{

    export class Window{
        public:
            Window(uint32_t width, uint32_t height);

            compl Window();

            uint32_t getWidth() const;
            uint32_t getHeight() const;
            void* getWindowHandle() const;

            void setSwapChain(SwapChain* swapChain);
            SwapChain* getSwapChain() const;

        private:
            uint32_t m_width;
            uint32_t m_height;
            void* m_windowHandle{nullptr};
            SwapChain* m_swapChain{nullptr};
    };

}