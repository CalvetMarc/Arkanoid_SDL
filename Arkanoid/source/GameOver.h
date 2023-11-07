#pragma once
#include "Engine/Graphics/Texture.h"


class GameOver
{
public:
    GameOver(SDL_Renderer* renderer);
    //~GameOver() = default;
    void Init();    
    void Render();
    void End();
private:
    SDL_Renderer* _renderer; 

    Texture* gameOver;
    SDL_Rect _destGameOverText;

    Texture* _ContinueText;
    SDL_Rect _continueRect;    
};

