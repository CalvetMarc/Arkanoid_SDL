#pragma once
#include "Brick.h"
#include "Vector2D.h"
#include "Engine/Graphics/Animation.h"
#include "../dependencies/XML/rapidxml.hpp"
#include "../dependencies/XML/rapidxml_utils.hpp"
#include "../dependencies/XML/rapidxml_iterators.hpp"
#include "../dependencies/XML/rapidxml_print.hpp"
#include <sstream>
#include "SDL_render.h"

class GameInfo
{
public:
	Brick ChargeMap(Vector2D<int>positionsToLoad);
	GameInfo() = default;
	GameInfo(SDL_Renderer* _renderer);
	void CopyPositionsVector(std::vector<Vector2D<float>>& _positions);
	
private:
	Brick _map[11][12];		
	BrickType CharToBrick(char a);
	void FillMap(SDL_Renderer* _renderer);
	std::vector<Vector2D<float>>positions;
	void PowerUpsInformation();
	int timePowerup;
	int probabilityPowerUp;
};

