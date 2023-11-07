#include "GameManager.h"


const int MS_PER_UPDATE = 16;

void GameManager::FillMap()
{
	gameStates.insert(std::make_pair(GameStates::GAME, new Game()));
    gameStates.insert(std::make_pair(GameStates::SPLASHSCREEN, new SplashScreen()));
    gameStates.insert(std::make_pair(GameStates::MENU, new MainMenu()));
    gameStates.insert(std::make_pair(GameStates::RANKINGREAD, new Ranking(new InputOperation("resources/Ranking.bin"))));
    gameStates.insert(std::make_pair(GameStates::RANKINGWRITE, new Ranking(new OutputOperation("resources/Ranking.bin"))));
}

void GameManager::Init()
{
    if (_currentStates == _lastStates) {
        changeGameStates = false;
    }
	_currentState->Start(_currentStates);
    //Audio::Instance(1);
    //Audio::Instance(1)->VolumeMusic(MIX_MAX_VOLUME / 4);
    /*Audio::Instance(0)->PauseMusic();
    Audio::Instance(1)->PlayMusic(1,-1);*/
}

void GameManager::Update(bool &keepPlaying)
{

    double current = SDL_GetTicks();
    double elapsedSeconds = current - lastTime;
    lastTime = current;
    lag += elapsedSeconds;

    //if(_currentStates != GameStates::SPLASHSCREEN)
    _currentState->HandleEvents(keepPlaying, _currentStates);
    

    while (lag >= MS_PER_UPDATE) {
        _currentState->Update(elapsedSeconds);
        lag -= MS_PER_UPDATE;
        if (lag < MS_PER_UPDATE && _currentStates != GameStates::SPLASHSCREEN) {
            _currentState->Render();
        }

    }

    if (_currentStates != _lastStates) {
        changeGameStates = true;
        _lastStates = _currentStates;        
    }
        
}

void GameManager::Release()
{
    _currentState->End();
    _currentState = gameStates.find(_currentStates)->second;
}

