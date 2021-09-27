#include <SDL2/SDL.h>
#include "headers/game.h"
#include "headers/init.h"

// check game.cpp for the game loop. All the headers are in the folder "headers"

int main(int argc, char* args[])
{
    if(!initialize())
      return EXIT_FAILURE;
     
    gameClass gameObject;
    gameObject.gameLoop();
    gameObject.quitGame();

    return EXIT_SUCCESS;
}
