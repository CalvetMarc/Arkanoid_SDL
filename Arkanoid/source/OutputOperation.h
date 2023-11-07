#pragma once
#include "FileAction.h"

class OutputOperation: public FileAction
{
public:
	OutputOperation(const std::string path);
	virtual void Init(const std::string)override;
	virtual void HandleEvents(bool& keepPlaying, GameStates& whichStates)override;
	virtual void Update()override;
	virtual void Render(SDL_Renderer* renderer)override;
	virtual void End()override;
	int points;
private:
	Texture* name;
	Texture* title;
	Texture* putName;
	SDL_Rect _destName;
	SDL_Rect _destTitle;
	SDL_Rect _destPutName;
	
	bool nameFilled = false;
	bool reWrite = false;
	bool completed = false;

	std::ofstream myFile;
	std::stringstream playerName;
	char CheckNameLetter(SDL_Event);
};

