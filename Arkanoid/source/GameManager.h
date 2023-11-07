#pragma once
#include "GameState.h"
#include <map>
#include "Game.h"
#include "GameInfo.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "Ranking.h"
#include "OutputOperation.h"
#include "InputOperation.h"

class GameManager
{
private:
	std::map<GameStates, GameState*> gameStates;	
	void FillMap();	
	double lastTime;
	double lag;
	GameState* _currentState;
	GameStates _currentStates;
	GameStates _lastStates;
	GameInfo information;

	
public:
	bool changeGameStates;
	GameManager() { _currentState = new SplashScreen(); changeGameStates = false; FillMap(); lastTime = SDL_GetTicks(); lag = 0.0;};
	void Init();	
	void Update(bool &keepPlaying);	
	void Release();
};


