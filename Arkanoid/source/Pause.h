#pragma once
#include "Engine/Graphics/Texture.h"
#include "Audio.h"

class Pause
{    
public:
     Pause(SDL_Renderer* renderer);
    // void Init() ;
     void Update(double elapsedSeconds);
     void Render();
     void End() ;
private:
    SDL_Renderer* _renderer;

    //SceneState sceneState;

    bool _isRunning;

    Texture* _PauseText;
    SDL_Rect _destPauseRect;

    Texture* _SoundOffText;
    SDL_Rect _destSoundOffRect;

    Texture* _SoundOnText;
    SDL_Rect _destSoundOnRect;

    //InputHandler* _inputHandler;


};

