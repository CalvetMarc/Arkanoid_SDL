#pragma once
#include "GameState.h"
#include "Engine/Graphics/Texture.h"
#include "Audio.h"

class MainMenu : public GameState
{
public:

    MainMenu() = default;

    virtual void Start(GameStates& whichStates) override;;
    virtual void HandleEvents(bool& keepPlaying, GameStates& whichStates) override;
    virtual bool Update(double elapsedSeconds)override;
    virtual void Render() override;
    virtual void End()override;
    //bool IsRunning();

    int stateSelect = 1;

private:
    void InitSDL();

    void CreateWindowAndRender();

private:

    /*GameState gameState;
    SceneState sceneState;*/

    bool _isRunning;

    SDL_Window* _window;
    SDL_Renderer* _renderer;


    Texture* _logoTexture;
    SDL_Rect _destLogoRect;


    Audio* _audio;


    //Menu stuff
    Texture* PlayText;
    Texture* RankText;
    Texture* AudioText;
    Texture* ExitText;
    Texture* ArrowText;


    SDL_Rect _destPlayTextRect;
    SDL_Rect _destRankTextRect;
    SDL_Rect _destAudioTextRect;
    SDL_Rect _destExitTextRect;
    SDL_Rect _destArrowTextRect;


    //InputHandler* _inputHandler;

    const int MS_PER_UPDATE = 16;
    double lastTime;
    double lag;
};

