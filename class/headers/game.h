#pragma once 

#include <SDL2/SDL.h>


class gameClass
{
    public:
    gameClass();
    void gameLoop();
    void quitGame();
    SDL_Renderer* getRenderer() const {return gRenderer;};


    protected:
    SDL_Window* gWindow;
    private:
    SDL_Renderer* gRenderer;
};

