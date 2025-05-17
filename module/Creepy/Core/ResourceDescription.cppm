module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Dump.hpp>
#endif

export module creepy.core.resourcedesc;

export import creepy.core.type;

export namespace Creepy{

    struct SwapChainDesc{
        uint32_t width;
        uint32_t height;
        void* windowHandle{nullptr};
    };
    
}