module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Graphics/RenderSystem.cppm>
#endif

export module creepy.graphics.graphicsengine;

import creepy.graphics.rendersystem;

namespace Creepy{
    
    export class GraphicsEngine{
        public:

        private:
            RenderSystem m_renderSystem;
    };

}