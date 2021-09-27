#pragma once
#include <unordered_map>
#include <vector>
#include <SDL2/SDL.h>


class gameObject
{
    public:
    gameObject(double x, double y, double width, double height,int id);
    gameObject();
    //virtual SDL_Renderer* ( std::vector<gameObject> objects);
    protected:
    double x , y, width, height;
    int id;
};
 
class button : public gameObject
{
    public:
    button(double x, double y, double width, double height,int id) 
    : gameObject(x, y,  width, height,id) {};
    double getFocal();
    void setCenter();
    bool isClicked(int id, std::vector<button> buttonMap);
    private:
    double x_center, y_center,id;
};

std::vector<button> initButtons();