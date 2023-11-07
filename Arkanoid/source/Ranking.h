#pragma once
#include "FileAction.h"

class Ranking : public GameState
{
public:
	Ranking(FileAction*whichOperation);
	virtual void Start(GameStates& whichStates)override;
	virtual void HandleEvents(bool& keepPlaying, GameStates& whichStates)override;
	virtual bool Update(double elapsedTime)override;
	virtual void Render()override;
	virtual void End()override;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;	
	FileAction* _whichOperation;

	void InitSDL();
	void CreateWindowAndRender();
};

