#include "headers/init.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>


bool initialize()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "ERROR. COULDN'T INITIALIZE SDL. " << SDL_GetError() << std::endl;
        return false;
    }
    if(IMG_Init(IMG_INIT_PNG) == 0)
    {
        std::cerr << "ERROR. COULDN'T INITIALIZE SDL IMAGE. " << IMG_GetError() << std::endl;
        return false;
    }
    if (TTF_Init() == -1)
    {
        std::cerr << "ERROR. COULDN'T INITIALIZE SDL TTF. " << TTF_GetError() << std::endl;
        return false;
    }

    
    return true;
}