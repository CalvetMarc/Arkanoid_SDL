#include "GameOver.h"


GameOver::GameOver(SDL_Renderer* renderer) : _renderer(renderer)
{
    
}

void GameOver::Init()
{

    //_inputHandler = new InputHandler();
    gameOver = new Texture(0, 0, _renderer, "GameOver");
    _ContinueText = new Texture(0, 0, _renderer, "ContinueText");
}

//void GameOver::Update(double elapsedSeconds)
//{
//
//}

void GameOver::Render()
{
    _destGameOverText.x = 245;
    _destGameOverText.y = -50;
    _destGameOverText.w = 300;
    _destGameOverText.h = 275;

    _continueRect.x = 45;
    _continueRect.y = 350;
    _continueRect.w = 700;
    _continueRect.h = 100;

    gameOver->Render(&_destGameOverText, 0);
    _ContinueText->Render(&_continueRect, 0);


   // SDL_RenderPresent(_renderer);

}

void GameOver::End()
{

    SDL_DestroyRenderer(_renderer);
    //SDL_DestroyWindow(_window);
}
