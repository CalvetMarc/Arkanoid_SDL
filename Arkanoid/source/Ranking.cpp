#include "Ranking.h"
#include "Exceptions/SDL_Exception.h"
#include <iostream>

Ranking::Ranking(FileAction* whichOperation) : _whichOperation(whichOperation)
{

}

void Ranking::Start(GameStates& whichStates)
{
	InitSDL();
	CreateWindowAndRender();
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);

	_whichOperation->Init("resources/Ranking.bin");
}

void Ranking::HandleEvents(bool& keepPlaying, GameStates& whichStates)
{
	_whichOperation->HandleEvents(keepPlaying, whichStates);
}

bool Ranking::Update(double elapsedTime)
{
	_whichOperation->Update();
	return false;
}

void Ranking::Render()
{
	SDL_RenderClear(_renderer);

	_whichOperation->Render(_renderer);

	SDL_RenderPresent(_renderer);
}

void Ranking::End()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
}

void Ranking::InitSDL()
{
	auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

	if (!isInitialized) {
		throw SDL_Exception(SDL_GetError());
	}
}

void Ranking::CreateWindowAndRender()
{
	SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &_window, &_renderer);

	if (_window == nullptr || _renderer == nullptr) {
		throw SDL_Exception(SDL_GetError());
	}
}
