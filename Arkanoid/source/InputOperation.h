#pragma once
#include "FileAction.h"

class InputOperation : public FileAction
{
public:
	InputOperation(const std::string path);
	virtual void Init(const std::string)override;
	virtual void HandleEvents(bool& keepPlaying, GameStates& whichStates)override;
	virtual void Update()override;
	virtual void Render(SDL_Renderer* renderer)override;
	virtual void End()override;
private:
	std::ifstream myFile;

	Texture* player1, *player2, *player3, *player4, *player5, *player6, *player7, *player8, *player9, *player10, *title;
	SDL_Rect _dest1, _dest2, _dest3, _dest4, _dest5, _dest6, _dest7, _dest8, _dest9, _dest10, _destTitle;

	

};

