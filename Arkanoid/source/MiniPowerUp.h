#pragma once
#include "PowerUp.h"

class MiniPowerUp : public PowerUp
{
public:
	MiniPowerUp(SDL_Renderer* renderer, int timeActive);
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
	~MiniPowerUp() = default;
	float powerUpXPosition;
	Vector2D<float>vectorForCollisionPU;
	Vector2D<float>vectorForCollisionPlayer;
	Hero* _followHero;
	SDL_Renderer* _renderer;
	Animation* _animation;
	SDL_Rect _destPowerUp;
	int percentSmaller;
	bool disappear = false;
	int _timeActive;
	std::chrono::steady_clock::time_point start;
	bool active = false;
	int originalSize = 0;
};

