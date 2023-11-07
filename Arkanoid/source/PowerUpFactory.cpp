#include "PowerUpFactory.h"


PowerUp* PowerUpFactory::Create(SDL_Renderer* renderer, int timeActive) const
{
    int random = rand() % 3;

	if (random == 0) {
		return new GiantPowerUp(renderer, timeActive);
	}
	else if (random == 1) {
		return new MiniPowerUp(renderer, timeActive);
	}
	else {
		return new SpeedPowerUp(renderer, timeActive);
	}
   
}
