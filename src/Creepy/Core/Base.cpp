module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Core/Base.cppm>
#endif

#include <print>

module creepy.core.base;

namespace Creepy{
    void Base::doSick(){
        std::println("Ok fen");
    }
}