module;

#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Core/Base.cppm>
    #include <Creepy/Dump.hpp>
#endif

module creepy.core.base;

import std;

namespace Creepy{
    void Base::doSick(){
        std::println("Ok fen");
    }
}