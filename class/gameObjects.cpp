#include "headers/gameObjects.h"
#include <unordered_map>
#include <SDL2/SDL.h>
#include <cmath>
#include <vector>

#define WIDTH 960
#define HEIGHT 720

gameObject::gameObject(double x, double y, double width, double height, int id)
 : x(x) , y(y) , width(width), height(height) , id(id) {}

gameObject::gameObject() {}

double button::getFocal()
{
    return sqrt( (pow (width * 0.5 ,2)) - (pow(height * 0.5,2)));
}

void button::setCenter()
{
    this->x_center = (2*x + width)*0.5;
    this->y_center = (2*y + height)*0.5;
}

std::vector<button> initButtons()
{
    std::vector<button> buttonMap;
    button tempButton((double)240,(double)240,(double)441,(double)153,0); 
    buttonMap.push_back(tempButton);  
    return buttonMap;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
}

bool button::isClicked(int id, std::vector<button> buttonMap)
{
    button &tempButton = buttonMap.at(id);
    int xMouse, yMouse ;
    SDL_GetMouseState(&xMouse,&yMouse);
    if(tempButton.x <= xMouse  && (tempButton.x + tempButton.width) > xMouse)
    {
        if(tempButton.y <= yMouse && (tempButton.y + tempButton.height) > yMouse)
         return true;
         else
         return false;
    } else
    return false;
}

/*SDL_Renderer*(std::vector<gameObject> obj)
{
    SDL_Renderer* placeholder;
    return placeholder;
}*/