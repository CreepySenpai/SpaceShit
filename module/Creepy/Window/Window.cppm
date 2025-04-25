module;

#include <cstdint>

export module creepy.window.window;


namespace Creepy{

    export class Window{
        public:
            Window(uint32_t width, uint32_t height);

            compl Window();
        private:
            uint32_t m_width;
            uint32_t m_height;
            void* m_windowHandle{nullptr};
    };

}