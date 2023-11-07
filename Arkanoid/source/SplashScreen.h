#pragma once
#include "GameState.h"
#include "Engine/Graphics/Texture.h"


class SplashScreen : public GameState
{
public:

    SplashScreen() = default;
    virtual void Start(GameStates& whichStates) override;

    virtual void HandleEvents(bool& keepPlaying, GameStates& whichStates);

    virtual bool Update(double elapsedSeconds) override;

    virtual void Render() override;

    virtual void End() override;

    bool timePassed = false;
private:
    void InitSDL();
    void CreateWindowAndRender();


private:

    SDL_Window* _window;
    SDL_Renderer* _renderer;
    SDL_Rect _destSplashRect;

    Texture* _splashTexture;


    int current_time;
    int start_time;
};



