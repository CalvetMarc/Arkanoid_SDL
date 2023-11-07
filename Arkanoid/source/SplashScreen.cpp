#include "SplashScreen.h"
#include "Exceptions/SDL_Exception.h"
#include <iostream>



void SplashScreen::Start(GameStates& whichStates)
{
    InitSDL();
    CreateWindowAndRender();
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

    _splashTexture = new Texture("resources/Splashscreen.jpg", _renderer, 0);
    _splashTexture->Init();
    _destSplashRect.x = 0;
    _destSplashRect.y = 0;
    _destSplashRect.w = 800;
    _destSplashRect.h = 600;
}

void SplashScreen::HandleEvents(bool& keepPlaying, GameStates& whichStates)
{
    if (timePassed) {
        whichStates = GameStates::MENU;
    }
}

bool SplashScreen::Update(double elapsedSeconds)
{
    Render();
    while (!timePassed) {
        current_time = SDL_GetTicks();
        
        if (current_time >= 5000) {
            
            timePassed = true;
            
        }
    }
    if (timePassed == true) {
        
    }
    return true;
}

void SplashScreen::Render()
{
    SDL_RenderClear(_renderer);
    _splashTexture->Render(&_destSplashRect, 0);

    SDL_RenderPresent(_renderer);
}

void SplashScreen::End()
{
    _splashTexture->Release();    
    delete _splashTexture;
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
   
}


void SplashScreen::InitSDL()
{
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

    if (!isInitialized) {
        throw SDL_Exception(SDL_GetError());
    }
}

void SplashScreen::CreateWindowAndRender()
{
    SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &_window, &_renderer);

    if (_window == nullptr || _renderer == nullptr) {
        throw SDL_Exception(SDL_GetError());
    }
}