#pragma once
#include "PowerUp.h"


class GiantPowerUp : public PowerUp
{
public:
	GiantPowerUp(SDL_Renderer* renderer, int timeActive);
	virtual void Appear(Hero* player, Vector2D<float>position) override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Activate()override;
	virtual bool PlayerCollision()override;
	virtual void Release()override;
	virtual bool ReturnDisappearState()override;
	virtual void ControlTime()override;
	virtual void ResetPower()override;
	virtual void ResetOtherPowers()override;
	~GiantPowerUp() = default;
	float powerUpXPosition;
	Hero* _followHero;
	SDL_Renderer* _renderer;
	Animation* _animation;
	SDL_Rect _destPowerUp;
	Vector2D<float>vectorForCollisionPU;
	Vector2D<float>vectorForCollisionPlayer;
	int percentBigger= 25;
	bool disappear = false;
	int _timeActive;
	std::chrono::steady_clock::time_point start;
	bool active = false;
	int originalSize = 0;

};

