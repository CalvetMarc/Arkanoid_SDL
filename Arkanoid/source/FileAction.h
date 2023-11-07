#pragma once
#include <string>
#include "GameState.h"
#include <fstream>
#include <sstream>
#include "SDL.h"
#include "Engine/Graphics/Texture.h"
#include <map>
#include <iostream>



class FileAction
{
public:
	FileAction(const std::string);
	virtual void Init(const std::string) = 0;
	virtual void HandleEvents(bool& keepPlaying, GameStates& whichStates) = 0;
	virtual void Update() = 0;
	virtual void Render(SDL_Renderer*renderer) = 0;
	virtual void End() = 0;

	//std::map<int, std::string>gameRanking;


	//std::map<int, int>::iterator a;
	//std::map<int, int>* b;
	//it = b->begin();
};

