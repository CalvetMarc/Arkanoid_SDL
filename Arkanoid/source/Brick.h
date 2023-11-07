#pragma once
#include <SDL_render.h>
#include "Engine/Graphics/Animation.h"
#include "Engine/Graphics/Texture.h"
#include "Engine/Input/Controller.h"

//class Texture;
//class Animation;
//class Controller;

enum class BrickType { N,H,F };


class Brick
{
public:
    Brick();
    Brick(SDL_Renderer* renderer, double angle, int destBrickRectX, int destBrickRectY, int destBrickRectW, int destBrickRectH, int brickXPos, BrickType type, bool powerUp, int timePUActive);
    void Init();
    void Release();
    void Update();
    void Render();
    void SetMaxMinWhenBreakN(int& minScoreWhenBreak, int& maxScoreWhenBreak);
    void SetMaxMinWhenBreakH(int& minScoreWhenBreak, int& maxScoreWhenBreak);
    BrickType _type;
    bool Print;
    int _currentBrickScore;
    bool UpdateNormalBrickXAnim();
    bool _powerUp;
    int _timePUActive;

private:
	
    int _hitsLeftToBreak;
    int _minScoreWhenBreak;
    int _maxScoreWhenBreak;  
    SDL_Renderer* _renderer; 
    Animation* _brickAnimation;
    SDL_Rect _destBrickRect;
    float _brickXPosition;
    double _angle;
    SDL_Rect _sourceRect;
    bool isBreak;


};

