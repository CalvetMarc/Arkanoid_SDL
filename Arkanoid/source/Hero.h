#pragma once
#ifndef SDLPROJECT_HERO_H
#define SDLPROJECT_HERO_H


#include <SDL_render.h>
#include <vector>
#include "Engine/Graphics/Animation.h"
#include "Engine/Graphics/Texture.h"


class Texture;
class Animation;
class Controller;

class Hero {
public:
    

    Hero(SDL_Renderer* renderer, Controller* controller, double angle, int destHeroRectX, int destHeroRectY, int destHeroRectW, int destHeroRectH, int heroXPos);
    void Init();
    void Release();

    void Update(double elapsedSeconds);

    void MoveUp();
    void MoveDown();
    void PutUpOff();
    void PutDownOff();
    
    void Render();
    float speed;
    float _points;
    float _heroYPosition;
    float _heroXPosition;
    SDL_Rect _destHeroRect;
    int originalSpeed;
    int originalWidth;
    int simultanyPowerUps = 0;

private:
    SDL_Renderer* _renderer;
    Controller* _controller;  
    Animation* _heroAnimation;
    SDL_Rect sourceRect;
    //float _heroYPosition;
    double _angle;
    bool up;
    bool down;
    
};


#endif //SDLPROJECT_HERO_H
