#pragma once
#include <iostream>
#include "gameObjects.h"
#include <SDL2/SDL.h>
#include <vector>

#define SizeO 3

class gameScene
{
    public:
    gameScene();
    gameScene(SDL_Renderer* tempRenderer);
    SDL_Renderer* loadImageToScreen(SDL_Renderer* tempRenderer , std::string imagePath , double x, int y, int width, int height,int i);
    SDL_Renderer* updateScene( SDL_Renderer* tempRender);
    void menuScene(SDL_Event menuEvent,std::vector<button> &buttonMap,gameScene* sceneManager);
    void gameSceneLogic(SDL_Event menuEvent,std::vector<button> &buttonMap,gameScene* sceneManager,double deltaTime);
    void destroyTextures();
    int id = 0, imgoff = 0, textoff = 0 ,y = 0;
    double time,x;
    private:
        struct imageLoad
    {
        std::string images;
        int width;
        int height;
        SDL_Texture* texture;
    };
    imageLoad loadIMG[SizeO];
    std::string fonts[0];
};