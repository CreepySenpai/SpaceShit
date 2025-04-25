
#ifdef CREEPY_INTELLISENSE
    #include <Creepy/Core/Base.cppm>
    #include <Creepy/Game/Game.cppm>
#endif

import creepy.core.base;
import creepy.game.game;

int main(int, char**, char**){

    Creepy::Base b{};
    b.doSick();

    Creepy::Game game{};

    game.Run();
}
