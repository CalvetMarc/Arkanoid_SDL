#pragma once
#include "Vector2D.h"
#include <SDL_render.h>
#include "Engine/Graphics/Animation.h"
#include "Engine/Graphics/Texture.h"
#include "Game.h"
#include "Hero.h"
#include "PowerUpFactory.h"
//#include "PowerUp.h"



class Texture;
class Animation;

//template <typename T>
//class Vector2D;

enum class Serve { NO, P1, P2 };

class Ball
{
public:

    Vector2D<float>vector;
    float _ballYPosition;
    float _ballXPosition;
    SDL_Rect _destBallRect;
    //int whoHitted;

    Ball(SDL_Renderer* renderer, double angle, int destBallRectX, int destBallRectY, int destBallRectW, int destBallRectH);

    void Init();

    void Update(double elapsedSeconds, Hero* hero1, Hero* hero2, Map* map, Serve GameServe);

    void Render();

    void Release();

    bool Pop1;
    bool Pop2;

private:
    SDL_Renderer* _renderer;
    Hero* _hero1;
    Hero* _hero2;
    PowerUpFactory factory;
    Animation* _ballAnimation;
    SDL_Rect sourceRect;
    double _angle;
    int ballSpeed;
    int whoHitted;
    Vector2D<float>ballPosition;
    std::vector<Vector2D<float>>UpdateNormalBrickAnimation;
    std::vector<PowerUp*>mapPowerUps;
    void PlayerCollision(Hero* hero1, Hero* hero2);
    void BrickCollision(Map* map, Hero* hero1, Hero* hero2);
    void ComproveBounceAndRespawn(Hero* hero1, Hero* hero2, Map* map, Serve GameServe);
    void UpdatePowerUps();
    void BounceSound();
    void LoseLife();

};

