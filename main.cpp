
#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Core/Base.cppm>
    #include <Creepy/Dump.hpp>
#endif

import creepy.core.base;
import creepy.game.game;

int main(int argc, char** argv, char** envr){

    Creepy::Base b{};
    b.doSick();

    Creepy::Game game{};

    game.Run();
}
