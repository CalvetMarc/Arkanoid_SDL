#include "Audio.h"

Audio::Audio()
{
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        std::cout << "Unable to initialize SDL_mixer audio systems";
    }
    if (!soundtrack) std::cout << "Unable to load the Mix_Music soundtrack";


}

Audio::~Audio()
{
}

void Audio::MixFreeChannels(int value)
{
    Mix_ReserveChannels(value);
}

void Audio::MixFreeChunk()
{
    //Mix_FreeChunk(sample);
    //if (sample == nullptr) { std::cout << "sample is nothing\n"; }
}

//void Audio::PlayCollisionEffect() {
//    Mix_PlayChannel(-1, sample, 0);
//}




void Audio::PauseMusic()
{
    Mix_PauseMusic();
    musicPaused = true;
}

void Audio::PlayMusic(int _value)
{
    Mix_PlayMusic(soundtrack, _value);
}

void Audio::PlayEffect(int _value)
{
    Mix_PlayMusic(soundeffect, _value);
}

void Audio::ResumeMusic()
{
    Mix_ResumeMusic();
}

void Audio::RewindMusic()
{
    Mix_RewindMusic();
}

bool Audio::PausedMusic()
{
    return Mix_PausedMusic();
}

void Audio::VolumeMusic(int _value)
{
    Mix_VolumeMusic(_value);
}

void Audio::LoadMusicGame()
{
    soundtrack = { Mix_LoadMUS("resources/game_theme.mp3") };

}

void Audio::LoadMusicMenu()
{
    soundtrack = { Mix_LoadMUS("resources/menu.mp3") };
}

void Audio::CollisionSound()
{
    soundeffect = { Mix_LoadMUS("resources/Collision.mp3") };
    std::cout << "This plays sound\n";
}

void Audio::LoseLifeSound() {
    soundeffect = { Mix_LoadMUS("resources/Loselife.mp3") };
}

void Audio::GameOverMusic() {
    soundtrack = { Mix_LoadMUS("resources/GameOver.mp3") };
}

void Audio::VictoryMusic() {
    soundtrack = { Mix_LoadMUS("resources/Victory.mp3") };
}

Audio* Audio::audio = nullptr;
//Audio* Audio::effect = nullptr;