module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

export module creepy.window.window;

export import creepy.core.type;

namespace Creepy{

    export class Window{
        public:
            Window(uint32_t width, uint32_t height);

            compl Window();

            uint32_t getWidth() const;
            uint32_t getHeight() const;
            void* getWindowHandle() const;
            void setSwapChain(void* swapChain);
            
        private:
            uint32_t m_width;
            uint32_t m_height;
            void* m_windowHandle{nullptr};
            void* m_swapChain{nullptr};
    };

}