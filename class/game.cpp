#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "headers/game.h"
#include "headers/scenes.h"
#include "headers/gameObjects.h"

#define WIDTH 960
#define HEIGHT 720

gameClass::gameClass()
    {
        this->gWindow = SDL_CreateWindow("Paint Game Jam", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,WIDTH, HEIGHT, 0);
        this->gRenderer = SDL_CreateRenderer(this->gWindow, -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    }

// Gameloop -> Here wil occour all the events

void gameClass::gameLoop()
{
    bool quit = false;
    SDL_Event eManager;
    std::vector<button> gButtons;
    gButtons = initButtons();
    gameScene sceneManager(this->gRenderer);
    double oldtime = 0;
    while(!quit)
    { 
        double currentTime = static_cast<double>(SDL_GetPerformanceCounter() / SDL_GetPerformanceFrequency());
        double deltaTime = currentTime - oldtime;
        oldtime = currentTime;
        SDL_Event &eManageRef = eManager;
        while(SDL_PollEvent(&eManageRef))
        {
            if(eManager.type == SDL_QUIT)
             quit = true;
        }
        // id = 0 -> menu scene , id = 1 -> game scene
        if(sceneManager.id == 0)
            sceneManager.menuScene(eManageRef,gButtons,&sceneManager);
        if(sceneManager.id == 1)
            sceneManager.gameSceneLogic(eManager,gButtons,&sceneManager,deltaTime);
        //this set ups the renderer.
       this->gRenderer = sceneManager.updateScene(this->gRenderer);
        SDL_RenderPresent(this->gRenderer);
        SDL_RenderClear(this->gRenderer);
    }
    sceneManager.destroyTextures();
}

// when game ends

void gameClass::quitGame()
{

    SDL_DestroyWindow(this->gWindow);

    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}
