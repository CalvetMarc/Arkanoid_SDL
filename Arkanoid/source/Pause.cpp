#include "Pause.h"

Pause::Pause(SDL_Renderer* renderer) : _renderer(renderer)
{

}

//void Pause::Init()
//{
//    
//    //_inputHandler = new InputHandler();
//    _PauseText = new Texture(0, 0, _renderer, "PauseText");
//    if(Audio::Instance()->PausedMusic()){
//        _SoundOffText = new Texture(0, 0, _renderer, "SoundTextOff");
//    }
//    else if (!Audio::Instance()->PausedMusic()) {
//        _SoundOnText = new Texture(0, 0, _renderer, "SoundTextOn");
//    }
//}

void Pause::Update(double elapsedSeconds)
{
    _PauseText = new Texture(0, 0, _renderer, "PauseText");
    if (Audio::Instance()->PausedMusic()) {
        _SoundOffText = new Texture(0, 0, _renderer, "SoundTextOff");
    }
    else if (!Audio::Instance()->PausedMusic()) {
        _SoundOnText = new Texture(0, 0, _renderer, "SoundTextOn");
    }
}

void Pause::Render()
{
    _destPauseRect.x = 245;
    _destPauseRect.y = -50;
    _destPauseRect.w = 300;
    _destPauseRect.h = 275;

    _destSoundOffRect.x = 65;
    _destSoundOffRect.y = 350;
    _destSoundOffRect.w = 150;
    _destSoundOffRect.h = 125;

    _destSoundOnRect.x = 65;
    _destSoundOnRect.y = 350;
    _destSoundOnRect.w = 150;
    _destSoundOnRect.h = 125;

    _PauseText->Render(&_destPauseRect, 0);

    if (Audio::Instance()->PausedMusic()) {
        _SoundOffText->Render(&_destSoundOffRect, 0);
    }
    else if (!Audio::Instance()->PausedMusic()) {
        _SoundOnText->Render(&_destSoundOnRect, 0);
    }

    SDL_RenderPresent(_renderer);
    
}

void Pause::End()
{
    delete _PauseText;
    delete _SoundOffText;
    delete _SoundOnText;
    SDL_DestroyRenderer(_renderer);
    //SDL_DestroyWindow(_window);
}
