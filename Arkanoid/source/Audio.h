#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <sdl_mixer.h>
#include <iostream>

class Audio
{
private:
    Mix_Music* soundtrack{ Mix_LoadMUS("resources/menu.mp3") };
    Mix_Music* soundeffect{ Mix_LoadMUS("resources/Collision.mp3") };
    static Audio* audio;
    //static Audio* effect;

    //Mix_Chunk* sample = { Mix_LoadWAV("resources/sound.wav") };
    Audio();

public:

    static Audio* Instance()
    {
        if (audio == nullptr) { audio = new Audio; }
        return audio;
    };

    /*static Audio* InstanceEffect()
    {
        if (effect == nullptr) { effect = new Audio; }
        return effect;
    };*/

    ~Audio();
    void MixFreeChannels(int);
    void MixFreeChunk();
    void PlayCollisionEffect();



    void PauseMusic();
    void PlayMusic(int);
    void ResumeMusic();
    void RewindMusic();
    bool PausedMusic();
    void VolumeMusic(int);
    void LoadMusicGame();
    void LoadMusicMenu();
    void CollisionSound();
    void LoseLifeSound();
    void PlayEffect(int);
    void GameOverMusic();
    void VictoryMusic();

    bool musicPaused = false;
};

