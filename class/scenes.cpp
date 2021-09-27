#include "headers/scenes.h"
#include "headers/gameObjects.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

const int imageSize = 3;

#define WIDTH 960
#define HEIGHT 720

gameScene::gameScene() {};

gameScene::gameScene(SDL_Renderer * tempRenderer)
{
    loadIMG[0].images = "../images/background.png";
    loadIMG[0].width = 960;
    loadIMG[0].height= 720;
    loadIMG[1].images = "../images/background_game.png";
    loadIMG[1].width = 960;
    loadIMG[1].height= 720;
    loadIMG[2].images = "../images/player.png";
    loadIMG[2].width = 20;
    loadIMG[2].height= 20;

    SDL_Surface* tempsurface = NULL;
    SDL_Texture* tempTexture;

    for(int i = 0; i < imageSize ; i++)
    {
        if( !(tempsurface = IMG_Load(loadIMG[i].images.c_str())))
         {
        std::cerr << "FAILED TO ACQUIRE IMAGE . ERROR: " << IMG_GetError() << std::endl;
        }
        if( ! (tempTexture = SDL_CreateTextureFromSurface(tempRenderer,tempsurface)))
         {
                std::cerr << "FAILED TO CREATE TEXTURE . ERROR: " << SDL_GetError() << std::endl;
        }
          loadIMG[i].texture = tempTexture;
    }
    SDL_FreeSurface(tempsurface);
}

SDL_Renderer* gameScene::loadImageToScreen(SDL_Renderer* tempRenderer , std::string imagePath, double x, int y, int width, int height,int i)
{
    SDL_FRect tempRect;
   bool exitLoop = false;
    while(!exitLoop)
  { 
    tempRect.x = x;
    tempRect.y = (double)y;
    tempRect.w = (double)width;
    tempRect.h = (double)height;
    SDL_RenderCopyF(tempRenderer, loadIMG[i].texture, NULL,&tempRect);
    if(width == 960)
      {  if(x < 0)
        {
             x = (double)960 + x;
             exitLoop = false;
         }else
         exitLoop = true;
      }
      else
      exitLoop = true;
  }
    return tempRenderer;
}

SDL_Renderer* gameScene::updateScene(SDL_Renderer * tempRenderer)
{
    switch(this->id)
    {
        case 0:
                for(int i = 0 ; i < imageSize - 2 ; i++)
                    tempRenderer = loadImageToScreen(tempRenderer,loadIMG[i].images,0,0,loadIMG[i].width,loadIMG[i].height,i);
                break;
        case 1:
                for(int i = 0 + this->imgoff; i < imageSize ; i++)
                    tempRenderer = loadImageToScreen(tempRenderer,loadIMG[i].images,this->x,0,loadIMG[i].width,loadIMG[i].height,i);
                break;
    }
    return tempRenderer;
}

void gameScene::menuScene(SDL_Event menuEvent, std::vector<button> &buttonMap,gameScene *sceneManager)
{
    if(menuEvent.type == SDL_MOUSEBUTTONDOWN)
    {
        for(int x = 0; x < buttonMap.size() ; x++)
         if( buttonMap.at(x).isClicked(x,buttonMap) )
         {
                switch(x)
                {
                    case 0:
                        sceneManager->id = 1;
                        sceneManager->imgoff = 1;
                        return;
                }
         }
    }
}

void gameScene::gameSceneLogic(SDL_Event menuEvent,std::vector<button> &buttonMap,gameScene* sceneManager, double deltaTime)
{
     double mov = (double)5.0 * deltaTime;
      const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if(keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D])
        sceneManager->x -= mov;
    if(keystates[SDL_SCANCODE_LEFT] ||  keystates[SDL_SCANCODE_A])
        sceneManager->x +=mov;
}

void gameScene::destroyTextures()
{
    for(int i = 0; i < imageSize ; i++)
    {       
         SDL_DestroyTexture(loadIMG[i].texture);
    }
    
}
