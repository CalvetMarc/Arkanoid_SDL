#pragma once
#include "GiantPowerUp.h"
#include "MiniPowerUp.h"
#include "SpeedPowerUp.h"



class PowerUpFactory
{
public:

	PowerUp* Create(SDL_Renderer* renderer, int timeActive)const;
	
	
};

